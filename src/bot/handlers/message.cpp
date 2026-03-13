#include "bot/bot_app.hpp"

#include "bot/utils/text_utils.hpp"

#include <userver/logging/log.hpp>

#include <format>

namespace tg_bot {
void BotApp::HandleMessage(const tg::Message& message) {
    if (message.text->front() == '/') {
        HandleCommand(message);
        return;
    }
    if (*message.text == "makeMePremiumUser") {
        user_storage.MakeUserPremium(message.from->id, 1);
        return;
    }

    const auto& text = *message.text;
    auto words = SplitText(text);
    size_t word_count = words.size();
    size_t char_count = text.size();
    user_storage.SaveText(message.from->id, *message.text);

    std::string response = std::format(
        "✅ Text saved!\n\n"
        "📊 Statistics:\n"
        "• Characters: {}\n"
        "• Words: {}\n\n"
        "Now use @{} in any chat to send it!",
        char_count, word_count, *bot.GetMe().username);

    bot.SendMessage(message.chat.id, response, std::nullopt, std::nullopt, std::nullopt, "HTML");
}

}  // namespace tg_bot
