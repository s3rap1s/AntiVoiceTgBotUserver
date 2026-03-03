#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/keyboard_button.hpp>

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

void Serialize(const ReplyKeyboardMarkup& obj, ValueBuilder& builder);

}  // namespace tg
