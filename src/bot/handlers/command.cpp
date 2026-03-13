#include "bot/bot_app.hpp"

#include "bot/config.hpp"

#include <format>

namespace tg_bot {

namespace {

void HandleSaveTextStartCommand(tg::BotApi& bot, const std::string& alias, const tg::Message& message) {
    const std::string offer_text = std::format(
        "🤖 Hey! I'm a bot for gradual message sending.\n"
        "If you don't wanna type some text in inline mode or your text too long to handle (due to Telegram "
        "limitations😔):\n"
        "1. Send your text directly to this bot (up to {} characters)\n"
        "2. Use @{} in any chat\n"
        "3. Choose sending speed\n",
        "Send /start to check out the bot's functionality", alias);
    bot.SendMessage(message.chat.id, offer_text, std::nullopt, std::nullopt, std::nullopt, "HTML");
}

void HandleOfferPremiumStartCommand(tg::BotApi& bot, const tg::Message& message) {
    const std::string offer_text =
        "<b>💎 Premium version</b>\n\n"
        "• Ability to view full text without waiting\n"
        "• Prohibiting other premium users from viewing the full text\n\n"
        "Send /start to check out the bot's functionality";
    bot.SendMessage(message.chat.id, offer_text, std::nullopt, std::nullopt, std::nullopt, "HTML");
}

void HandleStartCommand(tg::BotApi& bot, const std::string& alias, const tg::Message& message) {
    const std::string general_info = std::format(
        "<b>🤖 Hi!</b> I'm a bot for gradual message sending.\n\n"
        "<b>📝 How to use:</b>\n\n"
        "<b>🤏 For short messages</b> (up to {} characters):\n"
        "1. Type @{} text in any chat\n"
        "2. Choose sending speed\n\n"
        "<b>🫷 🫸 For long messages:</b>\n"
        "1. Send your text directly to this bot (up to {} characters)\n"
        "2. Use @{} in any chat\n"
        "3. Choose sending speed\n",
        MAX_QUERY_SIZE, alias, MAX_MESSAGE_SIZE, alias);
    std::string speeds_info = "\n<b>⚡ Available speeds:</b>\n";
    for (const auto& speed : SPEEDS) {
        speeds_info +=
            std::format("{} - {} words per {:.1f} seconds\n", speed.title, speed.words_per_chunk, speed.delay);
    }
    std::string commands_info = "\n<b>📋 Commands:</b>\n";
    for (const auto& command : COMMANDS) {
        commands_info += std::format("{} - {}\n", command.command, command.description);
    }
    std::string options_info = std::format(
        "\n<b>🔧 Options:</b>\n"
        "{} - insert this at the beginning of the query so that "
        "the displayed text remains in the message",
        ACCUMULATE_COMMAND);
    const std::string full_text = general_info + speeds_info + commands_info + options_info;
    bot.SendMessage(message.chat.id, full_text, std::nullopt, std::nullopt, std::nullopt, "HTML");
}

void HandleClearCommand(tg::BotApi& bot, const tg::Message& message, UserStorage& user_storage) {
    user_storage.ClearText(message.from->id);
    std::string text = "🧹Saved text cleared!";
    bot.SendMessage(message.chat.id, text);
}

}  // namespace

void BotApp::HandleCommand(const tg::Message& message) {
    if (!message.text || message.text->empty()) return;

    const std::string alias = *bot.GetMe().username;
    const std::string text = *message.text;

    const auto first_space = text.find(' ');
    const std::string command_token = text.substr(0, first_space);
    const std::string command_arg = first_space == std::string::npos ? std::string{} : text.substr(first_space + 1);

    if (command_token == START_COMMAND.command) {
        if (!command_arg.empty()) {
            const std::string param = command_arg;
            if (param == OFFER_PREM_ARG) {
                HandleOfferPremiumStartCommand(bot, message);
                return;
            } else if (param == SAVE_TEXT_ARG) {
                HandleSaveTextStartCommand(bot, alias, message);
                return;
            }
        }
        HandleStartCommand(bot, alias, message);
    } else if (command_token == CLEAR_COMMAND.command) {
        HandleClearCommand(bot, message, user_storage);
    }
}

}  // namespace tg_bot
