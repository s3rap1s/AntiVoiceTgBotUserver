#pragma once

#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

#include <tg/types/response_parameters.hpp>

namespace tg {

enum class ApiErrorKind {
    kTransport,
    kHttp,
    kProtocol,
    kParse,
};

constexpr std::string_view ToString(ApiErrorKind kind) noexcept {
    switch (kind) {
        case ApiErrorKind::kTransport:
            return "transport";
        case ApiErrorKind::kHttp:
            return "http";
        case ApiErrorKind::kProtocol:
            return "protocol";
        case ApiErrorKind::kParse:
            return "parse";
    }

    return "unknown";
}

struct ApiError final {
    ApiErrorKind kind{ApiErrorKind::kProtocol};
    std::string method;
    std::optional<int> http_status;
    int error_code{0};
    std::string description;
    std::optional<ResponseParameters> response_parameters;
    std::optional<std::string> response_body;

    [[nodiscard]] std::optional<Integer> RetryAfter() const {
        if (!response_parameters) return std::nullopt;
        return response_parameters->retry_after;
    }

    [[nodiscard]] std::optional<Integer> MigrateToChatId() const {
        if (!response_parameters) return std::nullopt;
        return response_parameters->migrate_to_chat_id;
    }

    [[nodiscard]] bool IsRetryable() const { return kind == ApiErrorKind::kTransport || RetryAfter().has_value(); }

    [[nodiscard]] bool RequiresMigration() const { return MigrateToChatId().has_value(); }
};

class ApiException final : public std::runtime_error {
   public:
    explicit ApiException(ApiError err) : std::runtime_error(MakeMessage(err)), error(std::move(err)) {}

    [[nodiscard]] const ApiError& Error() const noexcept { return error; }

   private:
    ApiError error;

    static std::string MakeMessage(const ApiError& e) {
        std::string msg = "Telegram API ";
        msg += ToString(e.kind);

        if (!e.method.empty()) {
            msg += " in ";
            msg += e.method;
        }

        if (e.http_status) {
            msg += " [http_status=" + std::to_string(*e.http_status) + "]";
        }

        if (e.error_code != 0) {
            msg += " [error_code=" + std::to_string(e.error_code) + "]";
        }

        if (!e.description.empty()) {
            msg += ": ";
            msg += e.description;
        }

        if (const auto retry_after = e.RetryAfter()) {
            msg += " (retry_after=" + std::to_string(*retry_after) + "s)";
        }

        if (const auto migrate_to_chat_id = e.MigrateToChatId()) {
            msg += " (migrate_to_chat_id=" + std::to_string(*migrate_to_chat_id) + ")";
        }

        return msg;
    }
};

class ParseException final : public std::runtime_error {
   public:
    explicit ParseException(std::string message) : std::runtime_error(std::move(message)) {}
};

}  // namespace tg
