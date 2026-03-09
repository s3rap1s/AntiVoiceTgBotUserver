#include "json_client.hpp"

#include <algorithm>
#include <exception>
#include <string>
#include <string_view>

#include <userver/formats/json.hpp>
#include <userver/logging/log.hpp>

#include "../types/common.hpp"

namespace tg::internal {
namespace {

constexpr std::size_t kMaxLoggedBodySize = 512;

[[noreturn]] void ThrowApiError(ApiError error) { throw ApiException(std::move(error)); }

[[noreturn]] void ThrowParseError(std::string_view method, std::string description,
                                  std::optional<std::string> response_body = std::nullopt,
                                  std::optional<int> http_status = std::nullopt) {
    ThrowApiError(ApiError{
        .kind = ApiErrorKind::kParse,
        .method = std::string{method},
        .http_status = http_status,
        .error_code = 0,
        .description = std::move(description),
        .response_parameters = std::nullopt,
        .response_body = std::move(response_body),
    });
}

std::optional<std::string> MakeBodySnippet(std::string_view body) {
    if (body.empty()) return std::nullopt;

    const auto size = std::min(body.size(), kMaxLoggedBodySize);
    std::string snippet{body.substr(0, size)};
    if (size < body.size()) snippet += "...";
    return snippet;
}

std::optional<ResponseParameters> ParseResponseParameters(std::string_view method, const JsonClient::Json& root) {
    const auto params = root["parameters"];
    if (params.IsMissing() || params.IsNull()) return std::nullopt;
    try {
        return ParseComplex<ResponseParameters>(params);
    } catch (const std::exception& e) {
        auto description = std::string{"Failed to parse Telegram response parameters: "};
        description += e.what();
        ThrowParseError(method, std::move(description), MakeBodySnippet(userver::formats::json::ToString(root)));
    }
}

JsonClient::Json ParseJsonBody(std::string_view method, std::string_view body,
                               std::optional<int> http_status = std::nullopt) {
    try {
        return userver::formats::json::FromString(body);
    } catch (const std::exception& e) {
        auto description = std::string{"Failed to parse Telegram response JSON: "};
        description += e.what();
        ThrowParseError(method, std::move(description), MakeBodySnippet(body), http_status);
    }
}

[[noreturn]] void ThrowTelegramError(std::string_view method, ApiErrorKind kind, const JsonClient::Json& root,
                                     std::optional<int> http_status = std::nullopt,
                                     std::optional<std::string> response_body = std::nullopt) {
    const auto description = root["description"].As<std::string>("unknown error");
    const auto error_code = root["error_code"].As<int>(0);

    ThrowApiError(ApiError{
        .kind = kind,
        .method = std::string{method},
        .http_status = http_status,
        .error_code = error_code,
        .description = description,
        .response_parameters = ParseResponseParameters(method, root),
        .response_body = std::move(response_body),
    });
}

}  // namespace

JsonClient::JsonClient(userver::clients::http::Client& http, std::string token, std::string base_url)
    : http(http), token(std::move(token)), base_url(std::move(base_url)) {
    while (!this->base_url.empty() && this->base_url.back() == '/') {
        this->base_url.pop_back();
    }
}

std::string JsonClient::MakeUrl(std::string_view method) const {
    std::string url = base_url;
    url += "/bot";
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
        ThrowApiError(ApiError{
            .kind = ApiErrorKind::kTransport,
            .method = std::string{method},
            .http_status = std::nullopt,
            .error_code = 0,
            .description = "Null HTTP response",
            .response_parameters = std::nullopt,
            .response_body = std::nullopt,
        });
    }

    const auto status = static_cast<int>(resp->status_code());
    const auto body_sv = resp->body_view();
    const auto root = ParseJsonBody(method, body_sv, status);
    const auto body_snippet = MakeBodySnippet(body_sv);

    try {
        if (!resp->IsOk()) {
            LOG_ERROR() << "Telegram API HTTP error: method=" << method << " status=" << status
                        << " error_code=" << root["error_code"].As<int>(0)
                        << " description=" << root["description"].As<std::string>("<no description>");
            ThrowTelegramError(method, ApiErrorKind::kHttp, root, status, body_snippet);
        }

        const bool ok = root["ok"].As<bool>(false);
        if (!ok) {
            ThrowTelegramError(method, ApiErrorKind::kProtocol, root, status, body_snippet);
        }
    } catch (const ApiException&) {
        throw;
    } catch (const std::exception& e) {
        auto description = std::string{"Unexpected Telegram response schema: "};
        description += e.what();
        ThrowParseError(method, std::move(description), body_snippet, status);
    }

    return root;
}

JsonClient::Json JsonClient::CallResult(std::string_view method, const Json& payload,
                                        std::chrono::milliseconds timeout) {
    const auto root = CallJson(method, payload, timeout);
    return root["result"];
}

}  // namespace tg::internal
