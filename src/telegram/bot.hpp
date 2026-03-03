#pragma once

#include <string>

#include <userver/clients/http/client.hpp>
#include <userver/components/component_base.hpp>
#include <userver/engine/task/task_processor_fwd.hpp>
#include <userver/engine/task/task_with_result.hpp>

namespace tg_bot {

class TelegramBotComponent final : public userver::components::ComponentBase {
   public:
    static constexpr std::string_view kName = "telegram-bot";

    static userver::yaml_config::Schema GetStaticConfigSchema();

    TelegramBotComponent(const userver::components::ComponentConfig&, const userver::components::ComponentContext&);
    ~TelegramBotComponent() override;

   private:
    void Run();

    userver::clients::http::Client& http;
    userver::engine::TaskProcessor& tp;

    userver::engine::TaskWithResult<void> task;

    std::string token;
    int poll_timeout{20};
    int limit{100};
    int64_t offset{0};
};

}  // namespace tg_bot