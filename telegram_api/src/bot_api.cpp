#include "../include/bot_api.hpp"

#include <userver/formats/json.hpp>
#include <userver/logging/log.hpp>

#include "../include/errors.hpp"

namespace tg {

BotApi::BotApi(userver::clients::http::Client& http, std::string token)
    : http_(http), token_(std::move(token)) {}

std::string BotApi::MakeUrl(std::string_view method) const {
    std::string url = "https://api.telegram.org/bot";
    url += token_;
    url += "/";
    url += method;
    return url;
}

BotApi::Json BotApi::CallJson(std::string_view method, const Json& payload,
                              std::chrono::milliseconds http_timeout) {
    const auto body = userver::formats::json::ToString(payload);

    auto req = http_.CreateRequest()
                   .post(MakeUrl(method), body)
                   .headers({{"Content-Type", "application/json"}})
                   .timeout(http_timeout);

    auto resp = req.perform();
    if (!resp) {
        throw std::runtime_error(
            "Telegram API: http perform() returned null response");
    }
    if (!resp->IsOk()) {
        throw std::runtime_error("Telegram API: HTTP status not ok");
    }

    const auto root = userver::formats::json::FromString(resp->body_view());

    const bool ok = root["ok"].As<bool>(false);
    if (ok) return root;

    ApiError err;
    err.error_code = root["error_code"].As<int>(0);
    err.description = root["description"].As<std::string>("unknown error");

    const auto params = root["parameters"];
    if (!params.IsMissing()) {
        if (!params["retry_after"].IsMissing()) {
            err.retry_after = params["retry_after"].As<int>();
        }
        if (!params["migrate_to_chat_id"].IsMissing()) {
            err.migrate_to_chat_id =
                params["migrate_to_chat_id"].As<long long>();
        }
    }

    throw ApiException(std::move(err));
}

}  // namespace tg