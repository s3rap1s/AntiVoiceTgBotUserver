#include "gradual_editor.hpp"

#include "bot/keyboard.hpp"
#include "bot/types/speed.hpp"
#include "bot/utils/text_utils.hpp"

#include <userver/engine/sleep.hpp>

#include <chrono>
#include <string_view>
#include <vector>

void GraduallyUpdateMessage(tg::BotApi& bot, const std::string& inline_message_id, std::string_view full_text,
                            size_t speed, bool is_accumulated, tg_bot::MessageStorage& message_storage) {
    auto speed_info = GetSpeedInformation(speed);
    auto chunks = SplitTextByWordsCount(full_text, speed_info.words_per_chunk, is_accumulated);

    auto keyboard = CreateKeyboard(KeyboardMode::DuringUpdate);
    if (!is_accumulated) chunks.push_back("<i>End of the message</i>");

    for (size_t i = 0; i < chunks.size(); ++i) {
        std::string display_text = chunks[i];
        if (i + 1 + (is_accumulated ? 0 : 1) < chunks.size()) display_text += "...";

        if (i + 1 == chunks.size()) {
            if (is_accumulated)
                keyboard.inline_keyboard.clear();
            else
                keyboard.inline_keyboard.push_back({CreateListenButton()});
        }
        try {
            bot.EditMessageText(display_text, std::nullopt, std::nullopt, std::nullopt, inline_message_id, "HTML",
                                std::nullopt, std::nullopt, keyboard);
        } catch (const std::exception& e) {
            // if (!std::string(e.what()).starts_with("Bad Request: message is not modified")) {
            //     std::cerr << "Error editing message: " << e.what() << std::endl;
            //     break;
            // }
        }

        if (i + 1 < chunks.size()) {
            const auto delay =
                std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::duration<double>(speed_info.delay));
            userver::engine::SleepFor(delay);
        }
        if (is_accumulated) message_storage.ForgetMessage(inline_message_id);
    }
}
