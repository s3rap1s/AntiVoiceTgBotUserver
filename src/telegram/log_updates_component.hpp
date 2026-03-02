#pragma once

#include <chrono>
#include <cstdint>
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

    TelegramBotComponent(const userver::components::ComponentConfig&,
                         const userver::components::ComponentContext&);
    ~TelegramBotComponent() override;

   private:
    void Run();

    userver::clients::http::Client& http_;
    userver::engine::TaskProcessor& tp_;

    userver::engine::TaskWithResult<void> task_;

    std::string token_;
    std::chrono::seconds poll_timeout_{20};
    int limit_{100};
    std::int64_t offset_{0};
};

}  // namespace tg_bot