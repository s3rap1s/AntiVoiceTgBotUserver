#include "bot/bot_app.hpp"

#include "bot/config.hpp"

namespace tg_bot {

void BotApp::HandleCommand(const tg::Message& message) {
    if (!message.text || message.text->empty()) return;

    const std::string alias = bot.GetMe().username.value_or("your_bot");
    const std::string text = *message.text;

    const auto first_space = text.find(' ');
    const std::string command_token = text.substr(0, first_space);
    const std::string command_arg = first_space == std::string::npos ? std::string{} : text.substr(first_space + 1);

    if (command_token == START_COMMAND) {
        if (!command_arg.empty()) {
            const std::string param = command_arg;
            if (param == "offerPrem") {
                const std::string offer_text =
                    "<b>💎 Premium version</b>\n\n"
                    "• Ability to view full text without waiting\n"
                    "• Prohibiting other premium users from viewing the full text\n\n"
                    "Type /start to check out the bot's functionality";
                bot.SendMessage(message.chat.id, offer_text, std::nullopt, std::nullopt, std::nullopt, "HTML");
                return;
            }
        }
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
        std::string commands_info = std::format(
            "\n<b>📋 Commands:</b>\n"
            "{} - show this message\n"
            "{} - delete saved text\n",
            START_COMMAND, CLEAR_COMMAND);
        std::string options_info = std::format(
            "\n<b>🔧 Options:</b>\n"
            "{} - insert this at the beginning of the query so that "
            "the displayed text remains in the message",
            ACCUMULATE_COMMAND);
        const std::string full_text = general_info + speeds_info + commands_info + options_info;
        bot.SendMessage(message.chat.id, full_text, std::nullopt, std::nullopt, std::nullopt, "HTML");
    } else if (command_token == CLEAR_COMMAND) {
        user_storage.ClearText(message.from->id);
    }
}

}  // namespace tg_bot
