#pragma once

#include <tg/types/inline_keyboard_button.hpp>
#include <tg/types/inline_keyboard_markup.hpp>

#include <vector>

inline tg::InlineKeyboardButton CreateShowFullTextButton() {
    tg::InlineKeyboardButton button;
    button.text = "📖 Show full message";
    button.callback_data = "show_full";
    button.style = "primary";
    return button;
}

inline tg::InlineKeyboardButton CreateListenButton() {
    tg::InlineKeyboardButton button;
    button.text = "▶️ Listen";
    button.callback_data = "listen";
    button.style = "success";
    return button;
}

enum class KeyboardMode { kUpdating, kWaiting };

inline tg::InlineKeyboardMarkup CreateKeyboard(KeyboardMode mode) {
    tg::InlineKeyboardMarkup keyboard;
    keyboard.inline_keyboard.push_back({CreateShowFullTextButton()});
    if (mode == KeyboardMode::kWaiting) keyboard.inline_keyboard.push_back({CreateListenButton()});
    return keyboard;
}
