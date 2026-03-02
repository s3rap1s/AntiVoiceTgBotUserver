#include <tg/bot_api.hpp>

#include <chrono>
#include <stdexcept>
#include <string>

#include <userver/formats/json.hpp>
#include <userver/formats/json/value_builder.hpp>

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

    auto resp = http_.CreateRequest()
                    .post(MakeUrl(method), body)
                    .headers({{"Content-Type", "application/json"}})
                    .timeout(http_timeout)
                    .perform();

    if (!resp) {
        throw std::runtime_error("Telegram API: null HTTP response");
    }
    if (!resp->IsOk()) {
        throw std::runtime_error("Telegram API: HTTP status not OK");
    }

    const auto root = userver::formats::json::FromString(resp->body_view());

    const bool ok = root["ok"].As<bool>(false);
    if (ok) return root;

    const auto code = root["error_code"].As<int>(0);
    const auto desc = root["description"].As<std::string>("unknown error");

    // Можно потом расширить parsing parameters.retry_after и т.д.
    throw std::runtime_error("Telegram API ok=false, error_code=" +
                             std::to_string(code) + " description=" + desc);
}

Array<Update> BotApi::GetUpdates(std::int64_t offset,
                                 std::chrono::seconds long_poll_timeout,
                                 int limit) {
    userver::formats::json::ValueBuilder b;
    if (offset > 0) b["offset"] = offset;
    b["timeout"] = static_cast<int>(long_poll_timeout.count());
    b["limit"] = limit;

    // HTTP timeout должен быть > long_poll_timeout
    const auto http_timeout =
        std::chrono::duration_cast<std::chrono::milliseconds>(
            long_poll_timeout) +
        std::chrono::milliseconds{1500};

    const auto root = CallJson("getUpdates", b.ExtractValue(), http_timeout);

    Array<Update> out;
    const auto result = root["result"];
    out.reserve(result.GetSize());

    for (const auto& item : result) {
        // Требуется tg::Parse(Value, To<Update>) (твоя функция)
        out.push_back(item.As<Update>());
    }

    return out;
}

Integer BotApi::SendMessage(std::int64_t chat_id, std::string text) {
    userver::formats::json::ValueBuilder b;
    b["chat_id"] = chat_id;
    b["text"] = std::move(text);

    const auto root = CallJson("sendMessage", b.ExtractValue(),
                               std::chrono::milliseconds{5000});

    return root["result"]["message_id"].As<Integer>();
}

void BotApi::EditMessageText(std::int64_t chat_id, std::int64_t message_id,
                             std::string text) {
    userver::formats::json::ValueBuilder b;
    b["chat_id"] = chat_id;
    b["message_id"] = message_id;
    b["text"] = std::move(text);

    (void)CallJson("editMessageText", b.ExtractValue(),
                   std::chrono::milliseconds{5000});
}

}  // namespace tg