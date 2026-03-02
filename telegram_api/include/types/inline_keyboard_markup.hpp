#pragma once

#include <types/common.hpp>
#include <types/inline_keyboard_button.hpp>

namespace tg {

struct InlineKeyboardMarkup {
    Array<Array<InlineKeyboardButton>> inline_keyboard;
};

InlineKeyboardMarkup Parse(const Value& value, To<InlineKeyboardMarkup>);

}  // namespace tg
