#include <tg/types/keyboard_button.hpp>
#include <tg/types/reply_keyboard_markup.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ReplyKeyboardMarkup Parse(const Value& value, To<ReplyKeyboardMarkup>) {
    ReplyKeyboardMarkup obj{};
    obj.keyboard = ParseComplex<Array<Array<KeyboardButton>>>(value["keyboard"]);
    obj.is_persistent = ParseComplex<Optional<Boolean>>(value["is_persistent"]);
    obj.resize_keyboard = ParseComplex<Optional<Boolean>>(value["resize_keyboard"]);
    obj.one_time_keyboard = ParseComplex<Optional<Boolean>>(value["one_time_keyboard"]);
    obj.input_field_placeholder = ParseComplex<Optional<String>>(value["input_field_placeholder"]);
    obj.selective = ParseComplex<Optional<Boolean>>(value["selective"]);
    return obj;
}

void Serialize(const ReplyKeyboardMarkup& obj, ValueBuilder& builder) {
    internal::Put(builder, "keyboard", obj.keyboard);
    internal::Put(builder, "is_persistent", obj.is_persistent);
    internal::Put(builder, "resize_keyboard", obj.resize_keyboard);
    internal::Put(builder, "one_time_keyboard", obj.one_time_keyboard);
    internal::Put(builder, "input_field_placeholder", obj.input_field_placeholder);
    internal::Put(builder, "selective", obj.selective);
}

}  // namespace tg
