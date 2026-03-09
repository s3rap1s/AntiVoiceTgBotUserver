#pragma once

#include "bot/db/message_storage.hpp"
#include "bot/db/user_storage.hpp"

#include <userver/clients/http/client.hpp>
#include <userver/components/component_base.hpp>
#include <userver/engine/task/task_processor_fwd.hpp>
#include <userver/engine/task/task_with_result.hpp>

#include <cstdint>
#include <string>

namespace tg_bot {

class TelegramBotComponent final : public userver::components::ComponentBase {
   public:
    static constexpr std::string_view kName = "telegram-bot";

    static userver::yaml_config::Schema GetStaticConfigSchema();

    TelegramBotComponent(const userver::components::ComponentConfig&, const userver::components::ComponentContext&);
    ~TelegramBotComponent() override;

   private:
    void Run();

    userver::clients::http::Client& http_client;
    userver::engine::TaskProcessor& tp;
    userver::engine::TaskWithResult<void> task;

    MessageStorage message_storage;
    UserStorage user_storage;

    std::string token;
    std::string api_base_url{"https://api.telegram.org"};
    int poll_timeout{20};
    int limit{100};
    int64_t offset{0};

    int initial_backoff_ms{200};
    int max_backoff_ms{5000};
    int protocol_delay_ms{1000};
    int parse_delay_ms{5000};
    int retry_after_cap_seconds{120};
};

}  // namespace tg_bot
