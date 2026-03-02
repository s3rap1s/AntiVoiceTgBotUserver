#include <tg/types/inline_keyboard_button.hpp>
#include <tg/types/inline_keyboard_markup.hpp>

#include "common.hpp"

namespace tg {

InlineKeyboardMarkup Parse(const Value& value, To<InlineKeyboardMarkup>) {
    InlineKeyboardMarkup obj{};
    obj.inline_keyboard = ParseComplex<Array<Array<InlineKeyboardButton>>>(
        value["inline_keyboard"]);
    return obj;
}

}  // namespace tg
