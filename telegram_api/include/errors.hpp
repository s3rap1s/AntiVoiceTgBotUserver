#pragma once

#include <optional>
#include <stdexcept>
#include <string>

namespace tg {

struct ApiError final {
    int error_code{0};
    std::string description;

    // ResponseParameters (часть)
    std::optional<int> retry_after;
    std::optional<long long> migrate_to_chat_id;
};

class ApiException final : public std::runtime_error {
   public:
    explicit ApiException(ApiError err)
        : std::runtime_error(MakeMessage(err)), error(std::move(err)) {}

    ApiError error;

   private:
    static std::string MakeMessage(const ApiError& e) {
        std::string msg = "Telegram API error ";
        msg += std::to_string(e.error_code);
        msg += ": ";
        msg += e.description;
        if (e.retry_after) {
            msg += " (retry_after=" + std::to_string(*e.retry_after) + "s)";
        }
        return msg;
    }
};

}  // namespace tg