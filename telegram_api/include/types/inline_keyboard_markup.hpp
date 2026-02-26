#pragma once

#include "common.hpp"
#include "inline_keyboard_button.hpp"

namespace tg {

struct InlineKeyboardMarkup {
    Array<Array<InlineKeyboardButton>> inline_keyboard;
};

InlineKeyboardMarkup Parse(const Value& value, To<InlineKeyboardMarkup>);

}  // namespace tg
