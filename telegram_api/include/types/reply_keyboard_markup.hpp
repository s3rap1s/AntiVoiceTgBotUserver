#pragma once

#include "common.hpp"
#include "keyboard_button.hpp"

namespace tg {

struct ReplyKeyboardMarkup {
    Array<Array<KeyboardButton>> keyboard;
    Optional<Boolean> is_persistent;
    Optional<Boolean> resize_keyboard;
    Optional<Boolean> one_time_keyboard;
    Optional<String> input_field_placeholder;
    Optional<Boolean> selective;
};

ReplyKeyboardMarkup Parse(const Value& value, To<ReplyKeyboardMarkup>);

}  // namespace tg
