#include "json_client.hpp"

#include <stdexcept>
#include <string>

#include <userver/formats/json.hpp>
#include <userver/logging/log.hpp>

namespace tg::internal {

JsonClient::JsonClient(userver::clients::http::Client& http, std::string token) : http(http), token(std::move(token)) {}

std::string JsonClient::MakeUrl(std::string_view method) const {
    std::string url = "https://api.telegram.org/bot";
    url += token;
    url += "/";
    url += method;
    return url;
}

JsonClient::Json JsonClient::CallJson(std::string_view method, const Json& payload, std::chrono::milliseconds timeout) {
    const auto body = userver::formats::json::ToString(payload);

    auto resp = http.CreateRequest()
                    .post(MakeUrl(method), body)
                    .headers({{"Content-Type", "application/json"}})
                    .timeout(timeout)
                    .perform();

    if (!resp) {
        throw std::runtime_error("Telegram API: null HTTP response");
    }
    if (!resp->IsOk()) {
        auto body_sv = resp->body_view();
        auto status = resp->status_code();
        const auto root = userver::formats::json::FromString(body_sv);
        const auto code = root["error_code"].As<int>(0);
        const auto desc = root["description"].As<std::string>("<no description>");
        LOG_WARNING() << "Telegram API HTTP error: status=" << static_cast<int>(status) << " error_code=" << code
                      << " description=" << desc;
        throw std::runtime_error("Telegram API: HTTP status not OK");
    }

    const auto root = userver::formats::json::FromString(resp->body_view());

    const bool ok = root["ok"].As<bool>(false);
    if (ok) return root;

    const int code = root["error_code"].As<int>(0);
    const auto desc = root["description"].As<std::string>("unknown error");

    throw std::runtime_error("Telegram API ok=false, error_code=" + std::to_string(code) + " description=" + desc);
}

JsonClient::Json JsonClient::CallResult(std::string_view method, const Json& payload,
                                        std::chrono::milliseconds timeout) {
    const auto root = CallJson(method, payload, timeout);
    return root["result"];
}

}  // namespace tg::internal