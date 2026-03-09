#include "bot/bot_app.hpp"

#include "bot/config.hpp"
#include "bot/db/message_storage.hpp"
#include "bot/keyboard.hpp"
#include "bot/utils/text_utils.hpp"

namespace tg_bot {

void BotApp::HandleInlineQuery(const tg::InlineQuery& inline_query) {
    if (inline_query.query.size() > MAX_QUERY_SIZE - 20) {
        tg::InlineQueryResultButton button;
        button.start_parameter = SAVE_TEXT_ARG;
        button.text = "Query is too long, save text in PM";
        bot.AnswerInlineQuery(inline_query.id, {}, std::nullopt, std::nullopt, std::nullopt, button);
        return;
    }
    std::vector<tg::InlineQueryResult> results;
    std::string text = inline_query.query;
    auto first_non_space = std::find_if(text.begin(), text.end(), [](unsigned char ch) { return !std::isspace(ch); });
    text = std::string(first_non_space, text.end());
    std::string saved_text;
    bool is_accumulated = text.starts_with(ACCUMULATE_COMMAND);
    if (is_accumulated) {
        auto first_non_space_after_command = std::find_if(text.begin() + ACCUMULATE_COMMAND.size(), text.end(),
                                                          [](unsigned char ch) { return !std::isspace(ch); });
        text = std::string(first_non_space_after_command, text.end());
    }
    if (text.empty()) {
        auto saved_text = user_storage.GetText(inline_query.from.id);
        if (saved_text)
            text = *saved_text;
        else {
            tg::InlineQueryResultButton button;
            button.start_parameter = SAVE_TEXT_ARG;
            button.text = "Start typing query or save text in PM";
            bot.AnswerInlineQuery(inline_query.id, {}, std::nullopt, std::nullopt, std::nullopt, button);
            return;
        }
    }
    std::string description;
    if (!text.empty()) {
        description = "Query: " + text;
        if (is_accumulated) description = "(Accumulative mode) " + description;
        for (size_t speed = 0; speed < SPEEDS.size(); ++speed) {
            SpeedInformation speedConfig = GetSpeedInformation(speed);
            tg::InlineQueryResultArticle result;
            result.id = std::format("{}-{}", speed, (is_accumulated ? 1 : 0));
            result.title = speedConfig.title;
            result.description = speedConfig.speed_str + " - " + description;
            tg::InputTextMessageContent input_content;
            result.type = "article";
            input_content.message_text = "<i>Hidden message</i>";
            input_content.parse_mode = "HTML";
            result.input_message_content = input_content;
            result.reply_markup = CreateKeyboard(KeyboardMode::Waiting);
            results.push_back(result);
        }
        bot.AnswerInlineQuery(inline_query.id, results, std::nullopt, true);
    }
}

void BotApp::HandleChosenInlineResult(const tg::ChosenInlineResult chosen_inline_result) {
    if (!chosen_inline_result.query || !chosen_inline_result.inline_message_id) return;

    std::string query_id = chosen_inline_result.result_id;
    size_t separator_pos = query_id.find("-");
    size_t speed = ToInteger(query_id.substr(0, separator_pos));
    bool is_accumulated = query_id.substr(separator_pos + 1) == "1" ? true : false;
    std::string text = *chosen_inline_result.query;
    if (is_accumulated) text = text.substr(ACCUMULATE_COMMAND.size());
    if (text.empty()) {
        auto saved_text = user_storage.GetText(chosen_inline_result.from.id);
        if (saved_text) text = *saved_text;
    }
    std::string inline_message_id = *chosen_inline_result.inline_message_id;
    tg::Integer owner_id = chosen_inline_result.from.id;
    message_storage.SaveMessage(inline_message_id, text, owner_id, static_cast<int>(speed));
}
}  // namespace tg_bot
