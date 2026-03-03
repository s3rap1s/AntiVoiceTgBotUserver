#include <tg/types/reply_keyboard_remove.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ReplyKeyboardRemove Parse(const Value& value, To<ReplyKeyboardRemove>) {
    ReplyKeyboardRemove obj{};
    obj.remove_keyboard = ParseComplex<OptionalTrue>(value["remove_keyboard"]);
    obj.selective = ParseComplex<Optional<Boolean>>(value["selective"]);
    return obj;
}

void Serialize(const ReplyKeyboardRemove& obj, ValueBuilder& builder) {
    internal::Put(builder, "remove_keyboard", obj.remove_keyboard);
    internal::Put(builder, "selective", obj.selective);
}

}  // namespace tg
