#include <tg/bot_api.hpp>

#include <userver/formats/json/value_builder.hpp>

#include "internal/json_client.hpp"

namespace tg {

BotApi::BotApi(userver::clients::http::Client& http, std::string token, std::string base_url)
    : client(std::make_unique<internal::JsonClient>(http, std::move(token), std::move(base_url))), timeouts() {}

BotApi::~BotApi() = default;

}  // namespace tg
