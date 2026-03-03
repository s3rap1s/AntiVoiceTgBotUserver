#include <tg/bot_api.hpp>

#include <userver/formats/json/value_builder.hpp>

#include "internal/json_client.hpp"

namespace tg {

BotApi::BotApi(userver::clients::http::Client& http, std::string token)
    : client(std::make_unique<internal::JsonClient>(http, std::move(token))), timeouts() {}

BotApi::~BotApi() = default;

}  // namespace tg