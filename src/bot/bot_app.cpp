#include "bot_app.hpp"

#include <userver/engine/async.hpp>
#include <userver/engine/sleep.hpp>
#include <userver/logging/log.hpp>

namespace tg_bot {

BotApp::BotApp(tg::BotApi& bot, userver::engine::TaskProcessor& tp, MessageStorage& message_storage,
               UserStorage& user_storage)
    : bot(bot),
      message_storage(message_storage),
      user_storage(user_storage),
      dispatcher(bot, tp),
      background_tasks(tp) {
    dispatcher.OnInlineQuery(
        [this](tg::AsyncDispatcherContext&, const tg::InlineQuery& query) { HandleInlineQuery(query); });
    dispatcher.OnChosenInlineResult([this](tg::AsyncDispatcherContext&, const tg::ChosenInlineResult& result) {
        HandleChosenInlineResult(result);
    });
    dispatcher.OnCallbackQuery(
        [this](tg::AsyncDispatcherContext&, const tg::CallbackQuery& query) { HandleCallbackQuery(query); });
    dispatcher.OnMessage([this](tg::AsyncDispatcherContext&, const tg::Message& message) { HandleMessage(message); });
}

void BotApp::HandleUpdate(tg::Update update) { dispatcher.Dispatch(std::move(update)); }

}  // namespace tg_bot
