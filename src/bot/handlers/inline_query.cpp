#include "bot/bot_app.hpp"

#include "bot/config.hpp"
#include "bot/db/message_storage.hpp"
#include "bot/keyboard.hpp"
#include "bot/utils/text_utils.hpp"

#include <format>

namespace tg_bot {

void BotApp::HandleInlineQuery(const tg::InlineQuery& inline_query) {
    if (inline_query.query.size() > MAX_QUERY_SIZE - 20) {
        tg::InlineQueryResultButton button;
        button.start_parameter = SAVE_TEXT_ARG;
        button.text = "Query is too long, save text in PM";
        bot.AnswerInlineQuery(inline_query.id, {}, 1, std::nullopt, std::nullopt, button);
        return;
    }
    std::vector<tg::InlineQueryResult> results;
    std::string text = inline_query.query;
    auto first_non_space = std::find_if(text.begin(), text.end(), [](unsigned char ch) { return !std::isspace(ch); });
    text = std::string(first_non_space, text.end());
    std::string saved_text;
    if (text.empty()) {
        std::optional<std::string> saved_text;
        try {
            saved_text = user_storage.GetText(inline_query.from.id);
        } catch (const std::exception&) {
            tg::InlineQueryResultButton button;
            button.start_parameter = SAVE_TEXT_ARG;
            button.text = "Temporary error, try again later.";
            bot.AnswerInlineQuery(inline_query.id, {}, 1, std::nullopt, std::nullopt, button);
            return;
        }

        if (saved_text)
            text = *saved_text;
        else {
            tg::InlineQueryResultButton button;
            button.start_parameter = SAVE_TEXT_ARG;
            button.text = "Start typing text or save it in PM";
            bot.AnswerInlineQuery(inline_query.id, {}, 1, std::nullopt, std::nullopt, button);
            return;
        }
    }
    std::string description;
    if (!text.empty()) {
        description = "Query: " + text;
        for (size_t speed = 0; speed < SPEEDS.size(); ++speed) {
            SpeedInformation speedConfig = GetSpeedInformation(speed);
            tg::InlineQueryResultArticle result;
            result.id = std::format("{}", speed);
            result.title = speedConfig.title;
            result.description = speedConfig.speed_str + " - " + description;
            tg::InputTextMessageContent input_content;
            result.type = "article";
            input_content.message_text = "<i>Hidden message</i>";
            input_content.parse_mode = "HTML";
            result.input_message_content = input_content;
            result.reply_markup = CreateKeyboard(KeyboardMode::kWaiting);
            results.push_back(result);
        }
        bot.AnswerInlineQuery(inline_query.id, results, 1, true);
    }
}

void BotApp::HandleChosenInlineResult(const tg::ChosenInlineResult chosen_inline_result) {
    if (!chosen_inline_result.query || !chosen_inline_result.inline_message_id) return;
    std::string query_id = chosen_inline_result.result_id;
    size_t speed = ToInteger(query_id);
    std::string text = *chosen_inline_result.query;
    if (text.empty()) {
        std::optional<std::string> saved_text;
        try {
            saved_text = user_storage.GetText(chosen_inline_result.from.id);
        } catch (const std::exception&) {
            bot.EditMessageText("Temporary error, try again later.", std::nullopt, std::nullopt, std::nullopt,
                                chosen_inline_result.inline_message_id);
            return;
        }

        if (saved_text) text = *saved_text;
    }
    std::string inline_message_id = *chosen_inline_result.inline_message_id;
    tg::Integer owner_id = chosen_inline_result.from.id;
    try {
        message_storage.SaveMessage(inline_message_id, text, owner_id, static_cast<int>(speed));
    } catch (const std::exception&) {
        bot.EditMessageText("Temporary error, try again later.", std::nullopt, std::nullopt, std::nullopt,
                            chosen_inline_result.inline_message_id);
    }
}
}  // namespace tg_bot
