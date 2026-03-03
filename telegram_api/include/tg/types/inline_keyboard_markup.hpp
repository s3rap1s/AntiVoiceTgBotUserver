#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/inline_keyboard_button.hpp>

namespace tg {

struct InlineKeyboardMarkup {
    Array<Array<InlineKeyboardButton>> inline_keyboard;
};

InlineKeyboardMarkup Parse(const Value& value, To<InlineKeyboardMarkup>);

void Serialize(const InlineKeyboardMarkup& obj, ValueBuilder& builder);

}  // namespace tg
