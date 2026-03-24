#include "gradual_editor.hpp"

#include "bot/keyboard.hpp"
#include "bot/utils/text_utils.hpp"

#include <userver/engine/sleep.hpp>
#include <userver/logging/log.hpp>

#include <chrono>
#include <string_view>
#include <vector>

namespace tg_bot {

void GraduallyUpdateMessage(tg::BotApi& bot, const std::string& inline_message_id, std::string_view full_text,
                            size_t speed_id, UserStorage& user_storage) {
    auto speed_info = user_storage.GetSpeedInformation(speed_id);
    auto chunks = SplitTextByWordsCount(full_text, speed_info.words_per_chunk);

    auto keyboard = CreateKeyboard(KeyboardMode::kUpdating);
    chunks.push_back("<i>End of the message</i>");

    for (size_t i = 0; i < chunks.size(); ++i) {
        std::string display_text = chunks[i];
        if (i + 1 < chunks.size()) display_text += "...";

        if (i + 1 == chunks.size()) {
            keyboard.inline_keyboard.push_back({CreateListenButton()});
        }
        try {
            bot.EditMessageText(display_text, std::nullopt, std::nullopt, std::nullopt, inline_message_id, "HTML",
                                std::nullopt, std::nullopt, keyboard);
        } catch (const tg::ApiException& e) {
            if (e.Error().description.find("message is not modified") == std::string::npos) {
                throw;
            }
        } catch (const std::exception& e) {
            LOG_ERROR() << "Failed to modify message, inline_message_id=" << inline_message_id;
        }

        if (i + 1 < chunks.size()) {
            const auto delay_s = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::duration<double>(speed_info.delay_s));
            userver::engine::SleepFor(delay_s);
        }
    }
}

}  // namespace tg_bot