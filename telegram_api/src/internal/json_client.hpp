#pragma once

#include <chrono>
#include <string>
#include <string_view>

#include <userver/clients/http/client.hpp>
#include <userver/formats/json/value.hpp>

#include <tg/errors.hpp>

namespace tg::internal {

class JsonClient final {
   public:
    using Json = userver::formats::json::Value;

    JsonClient(userver::clients::http::Client& http, std::string token);

    Json CallJson(std::string_view method, const Json& payload, std::chrono::milliseconds timeout);

    Json CallResult(std::string_view method, const Json& payload, std::chrono::milliseconds timeout);

   private:
    std::string MakeUrl(std::string_view method) const;

    userver::clients::http::Client& http;
    std::string token;
};

}  // namespace tg::internal
