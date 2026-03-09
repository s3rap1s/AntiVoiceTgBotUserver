#include "tg_bot_component.hpp"

#include "bot/bot_app.hpp"

#include <tg/bot_api.hpp>
#include <tg/errors.hpp>

#include <userver/clients/http/component.hpp>
#include <userver/components/component.hpp>
#include <userver/components/component_config.hpp>
#include <userver/components/component_context.hpp>
#include <userver/engine/async.hpp>
#include <userver/engine/sleep.hpp>
#include <userver/logging/log.hpp>
#include <userver/yaml_config/schema.hpp>
#include <userver/yaml_config/yaml_config.hpp>

#include <algorithm>
#include <chrono>
#include <format>
#include <string>

namespace tg_bot {

namespace {

std::chrono::milliseconds NextExponentialDelay(std::chrono::milliseconds& backoff,
                                               std::chrono::milliseconds max_backoff) {
    const auto current = backoff;
    backoff = std::min(backoff * 2, max_backoff);
    return current;
}

std::chrono::milliseconds GetRetryDelay(const tg::ApiError& error, std::chrono::milliseconds& backoff,
                                        const std::chrono::milliseconds initial_backoff,
                                        const std::chrono::milliseconds max_backoff,
                                        const std::chrono::milliseconds protocol_delay,
                                        const std::chrono::milliseconds parse_delay,
                                        const std::chrono::seconds retry_after_cap) {
    if (const auto retry_after = error.RetryAfter()) {
        backoff = initial_backoff;
        const auto capped = std::clamp(*retry_after, int64_t{1}, retry_after_cap.count());
        return std::chrono::seconds{capped};
    }

    switch (error.kind) {
        case tg::ApiErrorKind::kTransport:
        case tg::ApiErrorKind::kHttp:
            return NextExponentialDelay(backoff, max_backoff);
        case tg::ApiErrorKind::kProtocol:
            backoff = initial_backoff;
            return protocol_delay;
        case tg::ApiErrorKind::kParse:
            backoff = initial_backoff;
            return parse_delay;
    }

    return NextExponentialDelay(backoff, max_backoff);
}

}  // namespace

userver::yaml_config::Schema TelegramBotComponent::GetStaticConfigSchema() {
    return userver::yaml_config::impl::SchemaFromString(std::string{R"(
type: object
description: Telegram bot component
defaultDescription: Telegram bot component
additionalProperties: false
properties:
  load-enabled:
    type: boolean
    description: Enable/disable this component
    default: true

  token:
    type: string
    description: Telegram bot token

  poll-timeout-seconds:
    type: integer
    description: getUpdates long polling timeout (seconds)
    default: 20
    minimum: 0

  limit:
    type: integer
    description: getUpdates limit (1..100)
    default: 100
    minimum: 1
    maximum: 100

  initial-backoff-ms:
    type: integer
    description: Initial retry backoff in milliseconds
    default: 200
    minimum: 1

  max-backoff-ms:
    type: integer
    description: Maximum retry backoff in milliseconds
    default: 5000
    minimum: 1

  protocol-delay-ms:
    type: integer
    description: Delay after protocol-level errors in milliseconds
    default: 1000
    minimum: 1

  parse-delay-ms:
    type: integer
    description: Delay after parse-level errors in milliseconds
    default: 5000
    minimum: 1

  retry-after-cap-seconds:
    type: integer
    description: Upper cap for Telegram retry_after in seconds
    default: 120
    minimum: 1
)"});
}

TelegramBotComponent::TelegramBotComponent(const userver::components::ComponentConfig& config,
                                           const userver::components::ComponentContext& context)
    : userver::components::ComponentBase(config, context),
      http_client(context.FindComponent<userver::components::HttpClient>().GetHttpClient()),
      tp(context.GetTaskProcessor("main-task-processor")),
      message_storage(context),
      user_storage(context) {
    const auto yaml = config.As<userver::yaml_config::YamlConfig>();
    token = yaml["token"].As<std::string>();
    poll_timeout = yaml["poll-timeout-seconds"].As<int>(20);
    limit = yaml["limit"].As<int>(100);
    initial_backoff_ms = yaml["initial-backoff-ms"].As<int>(200);
    max_backoff_ms = yaml["max-backoff-ms"].As<int>(5000);
    protocol_delay_ms = yaml["protocol-delay-ms"].As<int>(1000);
    parse_delay_ms = yaml["parse-delay-ms"].As<int>(5000);
    retry_after_cap_seconds = yaml["retry-after-cap-seconds"].As<int>(120);

    if (max_backoff_ms < initial_backoff_ms) {
        LOG_WARNING() << std::format(
            "Invalid retry config: max-backoff-ms ({}) < initial-backoff-ms ({}). Using initial as max.",
            max_backoff_ms, initial_backoff_ms);
        max_backoff_ms = initial_backoff_ms;
    }

    task = userver::engine::AsyncNoSpan(tp, [this] { Run(); });
}

TelegramBotComponent::~TelegramBotComponent() {
    task.RequestCancel();
    try {
        task.Get();
    } catch (...) {
    }
}

void TelegramBotComponent::Run() {
    tg::BotApi api(http_client, token);
    BotApp bot(api, tp, message_storage, user_storage);
    api.DeleteWebhook(true);
    const std::chrono::milliseconds initial_backoff{initial_backoff_ms};
    const std::chrono::milliseconds max_backoff{max_backoff_ms};
    const std::chrono::milliseconds protocol_delay{protocol_delay_ms};
    const std::chrono::milliseconds parse_delay{parse_delay_ms};
    const std::chrono::seconds retry_after_cap{retry_after_cap_seconds};
    std::chrono::milliseconds backoff{initial_backoff};

    while (!userver::engine::current_task::ShouldCancel()) {
        try {
            auto updates = api.GetUpdates(offset, limit, poll_timeout);

            for (auto& u : updates) {
                const auto update_id = u.update_id;
                bot.HandleUpdate(std::move(u));
                offset = std::max(offset, update_id + 1);
            }

            backoff = initial_backoff;
        } catch (const tg::ApiException& e) {
            const auto& error = e.Error();
            if (error.kind == tg::ApiErrorKind::kHttp && error.http_status.has_value() &&
                (*error.http_status == 401 || *error.http_status == 403)) {
                LOG_ERROR() << std::format(
                    "Fatal polling Telegram API error: kind={}, method={}, http_status={}, error_code={}, "
                    "message={}",
                    tg::ToString(error.kind), error.method, error.http_status.value_or(0), error.error_code, e.what());
                break;
            }

            const auto delay = GetRetryDelay(error, backoff, initial_backoff, max_backoff, protocol_delay, parse_delay,
                                             retry_after_cap);
            LOG_ERROR() << std::format(
                "Polling Telegram API error: kind={}, method={}, http_status={}, error_code={}, retry_after={}, "
                "delay_ms={}, message={}",
                tg::ToString(error.kind), error.method, error.http_status.value_or(0), error.error_code,
                error.RetryAfter().value_or(0), delay.count(), e.what());
            userver::engine::SleepFor(delay);
        } catch (const std::exception& e) {
            const auto delay = NextExponentialDelay(backoff, max_backoff);
            LOG_ERROR() << "Polling error: " << e.what();
            userver::engine::SleepFor(delay);
        }
    }
}

}  // namespace tg_bot
