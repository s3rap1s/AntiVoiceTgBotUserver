#include <types/keyboard_button.hpp>
#include <types/reply_keyboard_markup.hpp>

#include "common.hpp"

namespace tg {

ReplyKeyboardMarkup Parse(const Value& value, To<ReplyKeyboardMarkup>) {
    ReplyKeyboardMarkup obj{};
    obj.keyboard =
        ParseComplex<Array<Array<KeyboardButton>>>(value["keyboard"]);
    obj.is_persistent = ParseComplex<Optional<Boolean>>(value["is_persistent"]);
    obj.resize_keyboard =
        ParseComplex<Optional<Boolean>>(value["resize_keyboard"]);
    obj.one_time_keyboard =
        ParseComplex<Optional<Boolean>>(value["one_time_keyboard"]);
    obj.input_field_placeholder =
        ParseComplex<Optional<String>>(value["input_field_placeholder"]);
    obj.selective = ParseComplex<Optional<Boolean>>(value["selective"]);
    return obj;
}

}  // namespace tg
