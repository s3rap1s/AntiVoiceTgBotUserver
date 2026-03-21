#include "bot_app.hpp"

namespace tg_bot {

BotApp::BotApp(tg::BotApi& bot, userver::engine::TaskProcessor& tp, MessageStorage& message_storage,
               UserStorage& user_storage)
    : bot(bot), message_storage(message_storage), user_storage(user_storage), dispatcher(bot), background_tasks(tp) {
    dispatcher.OnInlineQuery([this](tg::UpdateContext&, const tg::InlineQuery& query) { HandleInlineQuery(query); });
    dispatcher.OnChosenInlineResult(
        [this](tg::UpdateContext&, const tg::ChosenInlineResult& result) { HandleChosenInlineResult(result); });
    dispatcher.OnCallbackQuery(
        [this](tg::UpdateContext&, const tg::CallbackQuery& query) { HandleCallbackQuery(query); });
    dispatcher.OnMessage([this](tg::UpdateContext&, const tg::Message& message) { HandleMessage(message); });
}

void BotApp::HandleUpdate(tg::Update update) {
    background_tasks.AsyncDetach(
        "handle-update-" + std::to_string(update.update_id),
        [this, update = std::move(update)]() mutable { dispatcher.Dispatch(std::move(update)); });
}

}  // namespace tg_bot
