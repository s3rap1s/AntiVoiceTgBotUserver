#include "bot.hpp"

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

TelegramBotComponent::TelegramBotComponent(const userver::components::ComponentConfig& cfg,
                                           const userver::components::ComponentContext& ctx)
    : userver::components::ComponentBase(cfg, ctx),
      http(ctx.FindComponent<userver::components::HttpClient>().GetHttpClient()),
      tp(ctx.GetTaskProcessor("main-task-processor")) {
    const auto yaml = cfg.As<userver::yaml_config::YamlConfig>();
    token = yaml["token"].As<std::string>();
    poll_timeout = yaml["poll-timeout-seconds"].As<int>(20);
    limit = yaml["limit"].As<int>(100);
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
    tg::BotApi bot(http, token);

    std::chrono::milliseconds backoff{200};

    while (!userver::engine::current_task::ShouldCancel()) {
        try {
            const auto updates = bot.GetUpdates(offset, poll_timeout, limit);

            for (const auto& u : updates) {
                offset = std::max(offset, u.update_id + 1);

                LOG_INFO() << "update_id=" << u.update_id;

                if (u.message && u.message->text) {
                    LOG_INFO() << "message.text=" << *u.message->text;
                    bot.SendMessage(u.message->chat.id, std::format("hi, <b>{}</b>", *u.message->chat.first_name),
                                    std::nullopt, std::nullopt, std::nullopt, "HTML");
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