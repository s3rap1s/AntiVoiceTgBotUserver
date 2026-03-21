#include "tg_bot_component.hpp"

#include "bot/bot_app.hpp"
#include "bot/config.hpp"

#include <tg/bot_api.hpp>
#include <tg/types/update.hpp>

#include <userver/clients/http/component.hpp>
#include <userver/components/component.hpp>
#include <userver/components/component_config.hpp>
#include <userver/components/component_context.hpp>
#include <userver/formats/json/serialize.hpp>
#include <userver/formats/parse/to.hpp>
#include <userver/server/handlers/exceptions.hpp>
#include <userver/storages/postgres/component.hpp>
#include <userver/yaml_config/merge_schemas.hpp>
#include <userver/yaml_config/yaml_config.hpp>

#include <optional>
#include <stdexcept>
#include <string>

namespace tg_bot {

namespace {

const std::string kSecretHeader = "X-Telegram-Bot-Api-Secret-Token";

}  // namespace

userver::yaml_config::Schema TelegramBotComponent::GetStaticConfigSchema() {
    return userver::yaml_config::MergeSchemas<userver::server::handlers::HttpHandlerBase>(R"(
type: object
description: Telegram bot component
defaultDescription: Telegram bot component
additionalProperties: false
properties:
  token:
    type: string
    description: Telegram bot token

  api-base-url:
    type: string
    description: Telegram Bot API base URL
    default: https://api.telegram.org

  webhook-url:
    type: string
    description: Public HTTPS URL that Telegram should call for webhook updates

  webhook-secret-token:
    type: string
    description: Secret token expected in X-Telegram-Bot-Api-Secret-Token header
    default: ""
)");
}

TelegramBotComponent::TelegramBotComponent(const userver::components::ComponentConfig& config,
                                           const userver::components::ComponentContext& context)
    : userver::server::handlers::HttpHandlerBase(config, context),
      http_client(context.FindComponent<userver::components::HttpClient>().GetHttpClient()),
      tp(context.GetTaskProcessor("main-task-processor")),
      message_storage(context.FindComponent<userver::components::Postgres>("postgres-db-1").GetCluster()),
      user_storage(context.FindComponent<userver::components::Postgres>("postgres-db-1").GetCluster()),
      webhook_url(config.As<userver::yaml_config::YamlConfig>()["webhook-url"].As<std::string>()),
      webhook_secret_token(config.As<userver::yaml_config::YamlConfig>()["webhook-secret-token"].As<std::string>("")),
      api(http_client, config.As<userver::yaml_config::YamlConfig>()["token"].As<std::string>(),
          config.As<userver::yaml_config::YamlConfig>()["api-base-url"].As<std::string>("https://api.telegram.org")),
      bot(api, tp, message_storage, user_storage) {
    if (webhook_url.empty()) {
        throw std::runtime_error("telegram-bot webhook-url must not be empty");
    }

    api.SetMyCommands({START_COMMAND, CLEAR_COMMAND});
    api.SetWebhook(webhook_url, std::nullopt, std::nullopt, std::nullopt, std::nullopt, true,
                   webhook_secret_token.empty() ? std::nullopt : std::make_optional(webhook_secret_token));
}

std::string TelegramBotComponent::HandleRequestThrow(const userver::server::http::HttpRequest& request,
                                                     userver::server::request::RequestContext&) const {
    if (!webhook_secret_token.empty()) {
        const auto& provided_secret = request.GetHeader(kSecretHeader);
        if (provided_secret != webhook_secret_token) {
            throw userver::server::handlers::Unauthorized(
                userver::server::handlers::ExternalBody{"Invalid Telegram webhook secret"});
        }
    }

    tg::Update update;
    try {
        const auto json = userver::formats::json::FromString(request.RequestBody());
        update = tg::Parse(json, userver::formats::parse::To<tg::Update>{});
    } catch (const std::exception& e) {
        throw userver::server::handlers::RequestParseError(userver::server::handlers::ExternalBody{
            std::string{"Failed to parse Telegram webhook payload: "} + e.what()});
    }

    const_cast<BotApp&>(bot).HandleUpdate(std::move(update));
    return {};
}

}  // namespace tg_bot
