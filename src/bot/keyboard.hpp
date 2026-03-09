#pragma once

#include <tg/types/inline_keyboard_button.hpp>
#include <tg/types/inline_keyboard_markup.hpp>

#include <vector>

inline tg::InlineKeyboardButton CreateShowFullTextButton() {
    tg::InlineKeyboardButton button;
    button.text = "📖 Show full message";
    button.callback_data = "show_full";
    return button;
}

inline tg::InlineKeyboardButton CreateListenAgainButton() {
    tg::InlineKeyboardButton button;
    button.text = "🔄 Listen again";
    button.callback_data = "relisten";
    return button;
}

inline tg::InlineKeyboardButton CreateListenButton() {
    tg::InlineKeyboardButton button;
    button.text = "▶️ Listen";
    button.callback_data = "listen";
    return button;
}

enum class KeyboardMode { DuringUpdate, JustSent, DoneUpdating };

inline tg::InlineKeyboardMarkup CreateKeyboard(KeyboardMode mode) {
    tg::InlineKeyboardMarkup keyboard;
    keyboard.inline_keyboard.push_back({CreateShowFullTextButton()});
    if (mode == KeyboardMode::JustSent)
        keyboard.inline_keyboard.push_back({CreateListenButton()});
    else if (mode == KeyboardMode::DoneUpdating)
        keyboard.inline_keyboard.push_back({CreateListenAgainButton()});
    return keyboard;
}
