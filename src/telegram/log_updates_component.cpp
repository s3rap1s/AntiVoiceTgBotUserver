#include "log_updates_component.hpp"

#include <algorithm>

#include <userver/clients/http/component.hpp>
#include <userver/components/component.hpp>
#include <userver/components/component_config.hpp>
#include <userver/components/component_context.hpp>
#include <userver/engine/async.hpp>
#include <userver/engine/sleep.hpp>
#include <userver/logging/log.hpp>
#include <userver/yaml_config/schema.hpp>
#include <userver/yaml_config/yaml_config.hpp>

#include <tg/bot_api.hpp>

namespace tg_bot {

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
)"});
}

TelegramBotComponent::TelegramBotComponent(
    const userver::components::ComponentConfig& cfg,
    const userver::components::ComponentContext& ctx)
    : userver::components::ComponentBase(cfg, ctx),
      http_(
          ctx.FindComponent<userver::components::HttpClient>().GetHttpClient()),
      tp_(ctx.GetTaskProcessor("main-task-processor")) {
    const auto yaml = cfg.As<userver::yaml_config::YamlConfig>();
    token_ = yaml["token"].As<std::string>();
    poll_timeout_ =
        std::chrono::seconds(yaml["poll-timeout-seconds"].As<int>(20));
    limit_ = yaml["limit"].As<int>(100);

    task_ = userver::engine::AsyncNoSpan(tp_, [this] { Run(); });
}

TelegramBotComponent::~TelegramBotComponent() {
    task_.RequestCancel();
    try {
        task_.Get();
    } catch (...) {
    }
}

void TelegramBotComponent::Run() {
    tg::BotApi api(http_, token_);

    std::chrono::milliseconds backoff{200};

    while (!userver::engine::current_task::ShouldCancel()) {
        try {
            const auto updates = api.GetUpdates(offset_, poll_timeout_, limit_);

            for (const auto& u : updates) {
                offset_ = std::max(offset_,
                                   static_cast<std::int64_t>(u.update_id + 1));

                LOG_INFO() << "update_id=" << u.update_id;

                if (u.message && u.message->text) {
                    LOG_INFO() << "message.text=" << *u.message->text;
                }
                if (u.inline_query) {
                    LOG_INFO() << "inline_query=" << u.inline_query->query;
                }
            }

            backoff = std::chrono::milliseconds{200};
        } catch (const std::exception& e) {
            LOG_WARNING() << "polling error: " << e.what();
            userver::engine::SleepFor(backoff);
            backoff = std::min(backoff * 2, std::chrono::milliseconds{5000});
        }
    }
}

}  // namespace tg_bot