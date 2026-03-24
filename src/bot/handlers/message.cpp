#include "bot/bot_app.hpp"

#include "bot/text.hpp"
#include "bot/utils/text_utils.hpp"

#include <userver/logging/log.hpp>

#include <format>

namespace tg_bot {

namespace {
void HandleCreateCustomSpeed(const tg::Message& message, tg::BotApi& bot, UserStorage& user_storage) {
    const auto& text = *message.text;
    const std::string try_again = ", try again or send /cancel";
    auto args = SplitText(text, '/');
    if (args.size() != 3) {
        bot.SendMessage(message.from->id, "❌ Invalid format" + try_again);
        return;
    }
    int words_per_chunk{};
    if (auto value = ToNumber<int>(args[0]); !value) {
        bot.SendMessage(message.from->id, "❌ Invalid words count" + try_again);
        return;
    } else {
        words_per_chunk = *value;
    }
    if (words_per_chunk <= 0) {
        bot.SendMessage(message.from->id, "❌ Words count must be greater than zero" + try_again);
        return;
    }
    float delay_s{};
    if (auto value = ToNumber<float>(args[1]); !value) {
        bot.SendMessage(message.from->id, "❌ Invalid delay value" + try_again);
        return;
    } else {
        delay_s = *value;
    }
    if (delay_s <= 0) {
        bot.SendMessage(message.from->id, "❌ Delay must be greater than zero" + try_again);
        return;
    }
    const auto title = args[2];
    if (!user_storage.SaveCustomSpeed(message.from->id, static_cast<size_t>(words_per_chunk), delay_s, title)) {
        bot.SendMessage(message.from->id, "❌ Try another title or send /cancel.");
    } else {
        bot.SendMessage(message.from->id, "✅ Custom speed saved successfully.");
        try {
            user_storage.ChangeState(message.from->id, std::nullopt);
        } catch (const std::exception&) {
            bot.SendMessage(message.from->id, TEMPORARY_ERROR);
            return;
        }
    }
}

void HandleSaveMessage(const tg::Message& message, tg::BotApi& bot, UserStorage& user_storage) {
    const auto& text = *message.text;
    auto words = SplitText(text, ' ');
    size_t word_count = words.size();
    size_t char_count = text.size();
    try {
        user_storage.SaveText(message.from->id, *message.text);
    } catch (const std::exception&) {
        bot.SendMessage(message.from->id, TEMPORARY_ERROR);
        return;
    }

    std::string response = std::format(
        "✅ Text saved!\n\n"
        "📊 Statistics:\n"
        "• Characters: {}\n"
        "• Words: {}\n\n"
        "Now use @{} in any chat to send it!",
        char_count, word_count, *bot.GetMe().username);

    bot.SendMessage(message.from->id, response, std::nullopt, std::nullopt, std::nullopt, "HTML");
}
}  // namespace

void BotApp::HandleMessage(const tg::Message& message) {
    if (message.text->front() == '/') {
        HandleCommand(message);
        return;
    }
    if (*message.text == "makeMePremiumUser") {
        try {
            user_storage.MakeUserPremium(message.from->id, 1);
        } catch (const std::exception&) {
            bot.SendMessage(message.from->id, TEMPORARY_ERROR);
            return;
        }
        return;
    }
    const auto state = user_storage.GetState(message.from->id);
    if (state.has_value()) {
        switch (*state) {
            case tg_bot::UserStorage::State::kAwaitingCustomSpeed:
                HandleCreateCustomSpeed(message, bot, user_storage);
                break;
            default:
                HandleSaveMessage(message, bot, user_storage);
        }
    } else {
        HandleSaveMessage(message, bot, user_storage);
    }
}

}  // namespace tg_bot
