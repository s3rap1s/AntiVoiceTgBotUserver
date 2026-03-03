#include <tg/types/inline_keyboard_button.hpp>
#include <tg/types/inline_keyboard_markup.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InlineKeyboardMarkup Parse(const Value& value, To<InlineKeyboardMarkup>) {
    InlineKeyboardMarkup obj{};
    obj.inline_keyboard = ParseComplex<Array<Array<InlineKeyboardButton>>>(value["inline_keyboard"]);
    return obj;
}

void Serialize(const InlineKeyboardMarkup& obj, ValueBuilder& builder) {
    internal::Put(builder, "inline_keyboard", obj.inline_keyboard);
}

}  // namespace tg
