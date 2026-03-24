#include "bot/bot_app.hpp"

#include "bot/config.hpp"
#include "bot/db/message_storage.hpp"
#include "bot/keyboard.hpp"
#include "bot/text.hpp"
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
            button.text = TEMPORARY_ERROR;
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
    std::vector<SpeedInformation> speeds;
    try {
        speeds = user_storage.GetUserSpeeds(inline_query.from.id);
    } catch (const std::exception&) {
        tg::InlineQueryResultButton button;
        button.start_parameter = SAVE_TEXT_ARG;
        button.text = TEMPORARY_ERROR;
        bot.AnswerInlineQuery(inline_query.id, {}, 1, std::nullopt, std::nullopt, button);
        return;
    }
    if (!text.empty()) {
        description = "Query: " + text;
        for (const auto& speed : speeds) {
            tg::InlineQueryResultArticle result;
            result.id = std::format("{}", speed.speed_id);
            result.title = speed.title;
            result.description = BuildSpeedStr(speed.words_per_chunk, speed.delay_s) + " - " + description;
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
    size_t speed_id;
    if (auto value = ToNumber<size_t>(query_id); !value) {
        LOG_ERROR() << "Failed to convert query_id to integer, query_id=" << query_id;
        speed_id = DEFAULT_SPEED_INDEX;
    } else {
        speed_id = static_cast<size_t>(*value);
    }
    std::string text = *chosen_inline_result.query;
    if (text.empty()) {
        std::optional<std::string> saved_text;
        try {
            saved_text = user_storage.GetText(chosen_inline_result.from.id);
        } catch (const std::exception&) {
            bot.EditMessageText(TEMPORARY_ERROR, std::nullopt, std::nullopt, std::nullopt,
                                chosen_inline_result.inline_message_id);
            return;
        }

        if (saved_text) text = *saved_text;
    }
    std::string inline_message_id = *chosen_inline_result.inline_message_id;
    tg::Integer owner_id = chosen_inline_result.from.id;
    try {
        message_storage.SaveMessage(inline_message_id, text, owner_id, static_cast<int>(speed_id));
    } catch (const std::exception&) {
        bot.EditMessageText(TEMPORARY_ERROR, std::nullopt, std::nullopt, std::nullopt,
                            chosen_inline_result.inline_message_id);
    }
}
}  // namespace tg_bot
