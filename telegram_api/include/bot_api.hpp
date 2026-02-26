#pragma once

#include <chrono>
#include <cstdint>
#include <string>
#include <string_view>

#include <userver/clients/http/client.hpp>
#include <userver/formats/json/value.hpp>

#include "types/common.hpp"
#include "types/update.hpp"

namespace tg {

class BotApi final {
   public:
    using Json = userver::formats::json::Value;

    explicit BotApi(userver::clients::http::Client& http, std::string token);

    // --- Updates ---
    Array<Update> GetUpdates(std::int64_t offset,
                             std::chrono::seconds long_poll_timeout, int limit);

    Integer SendMessage(std::int64_t chat_id, std::string text);

    void EditMessageText(std::int64_t chat_id, std::int64_t message_id,
                         std::string text);

   private:
    std::string MakeUrl(std::string_view method) const;

    Json CallJson(std::string_view method, const Json& payload,
                  std::chrono::milliseconds http_timeout);

    userver::clients::http::Client& http_;
    std::string token_;
};

}  // namespace tg