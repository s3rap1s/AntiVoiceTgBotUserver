#include "bot/bot_app.hpp"

#include "bot/config.hpp"
#include "bot/core/gradual_editor.hpp"
#include "bot/text.hpp"

#include <format>

namespace tg_bot {

void BotApp::HandleCallbackQuery(const tg::CallbackQuery& callback_query) {
    std::string alias = *bot.GetMe().username;
    if (callback_query.data == "show_full") {
        std::optional<MessageStorage::MessageInfo> result;
        try {
            result = message_storage.GetMessage(*callback_query.inline_message_id);
        } catch (const std::exception&) {
            bot.AnswerCallbackQuery(callback_query.id, TEMPORARY_ERROR);
            return;
        }

        if (result.has_value()) {
            auto [text, owner_id, speed] = result.value();
            tg::Integer sender_id = callback_query.from.id;
            bool is_owner = owner_id == sender_id;
            bool is_sender_premium = false;
            bool is_owner_premium = false;
            try {
                is_sender_premium = user_storage.IsPremiumUser(sender_id);
                is_owner_premium = user_storage.IsPremiumUser(owner_id);
            } catch (const std::exception&) {
                bot.AnswerCallbackQuery(callback_query.id, TEMPORARY_ERROR);
                return;
            }

            if ((is_sender_premium && !is_owner_premium) || is_owner)
                bot.AnswerCallbackQuery(callback_query.id, text, true);
            else {
                if (!is_sender_premium)
                    bot.AnswerCallbackQuery(callback_query.id, "", true,
                                            std::format("t.me/{}?start={}", alias, OFFER_PREM_ARG));
                else
                    bot.AnswerCallbackQuery(callback_query.id, "The sender is also a <b>💎Premium user</b>");
            }
        } else {
            bot.AnswerCallbackQuery(callback_query.id, "Message is deleted");
        }
    } else if (*callback_query.data == "listen") {
        const std::string inline_message_id = *callback_query.inline_message_id;
        std::optional<MessageStorage::MessageInfo> result;
        try {
            result = message_storage.GetMessage(inline_message_id);
        } catch (const std::exception&) {
            bot.AnswerCallbackQuery(callback_query.id, TEMPORARY_ERROR);
            return;
        }

        if (result.has_value()) {
            auto message_data = std::move(result.value());
            auto text = std::move(message_data.text);
            auto speed = message_data.speed;
            bot.AnswerCallbackQuery(callback_query.id);
            background_tasks.AsyncDetach(inline_message_id, [this, inline_message_id, text = std::move(text), speed] {
                GraduallyUpdateMessage(bot, inline_message_id, text, speed, user_storage);
            });
        } else {
            bot.AnswerCallbackQuery(callback_query.id, "Message is deleted");
        }
    }
}

}  // namespace tg_bot
