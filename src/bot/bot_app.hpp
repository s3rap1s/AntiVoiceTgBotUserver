#pragma once

#include "db/message_storage.hpp"
#include "db/user_storage.hpp"

#include <tg/async_dispatcher.hpp>
#include <tg/bot_api.hpp>
#include <tg/types/update.hpp>

#include <userver/concurrent/background_task_storage.hpp>
#include <userver/engine/task/task_processor_fwd.hpp>

namespace tg_bot {

class BotApp {
   public:
    BotApp(tg::BotApi& bot, userver::engine::TaskProcessor& task_processor, MessageStorage& message_storage,
           UserStorage& user_storage);

    void HandleUpdate(tg::Update update);

   private:
    void HandleMessage(const tg::Message& message);
    void HandleCommand(const tg::Message& message);
    void HandleInlineQuery(const tg::InlineQuery& inline_query);
    void HandleChosenInlineResult(const tg::ChosenInlineResult chosen_inline_result);
    void HandleCallbackQuery(const tg::CallbackQuery& callback_query);

    tg::BotApi& bot;
    MessageStorage& message_storage;
    UserStorage& user_storage;
    tg::AsyncDispatcher dispatcher;
    userver::concurrent::BackgroundTaskStorage background_tasks;
};

}  // namespace tg_bot
