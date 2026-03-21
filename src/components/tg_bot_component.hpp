#pragma once

#include "bot/bot_app.hpp"
#include "bot/db/message_storage.hpp"
#include "bot/db/user_storage.hpp"

#include <tg/bot_api.hpp>

#include <userver/clients/http/client.hpp>
#include <userver/engine/task/task_processor_fwd.hpp>
#include <userver/server/handlers/http_handler_base.hpp>

#include <string>

namespace tg_bot {

class TelegramBotComponent final : public userver::server::handlers::HttpHandlerBase {
   public:
    static constexpr std::string_view kName = "telegram-bot";

    static userver::yaml_config::Schema GetStaticConfigSchema();

    TelegramBotComponent(const userver::components::ComponentConfig&, const userver::components::ComponentContext&);

    std::string HandleRequestThrow(const userver::server::http::HttpRequest&,
                                   userver::server::request::RequestContext&) const override;

   private:
    userver::clients::http::Client& http_client;
    userver::engine::TaskProcessor& tp;

    MessageStorage message_storage;
    UserStorage user_storage;

    std::string webhook_url;
    std::string webhook_secret_token;

    tg::BotApi api;
    BotApp bot;
};

}  // namespace tg_bot
