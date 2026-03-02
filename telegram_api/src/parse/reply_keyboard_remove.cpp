#include <types/reply_keyboard_remove.hpp>

#include "common.hpp"

namespace tg {

ReplyKeyboardRemove Parse(const Value& value, To<ReplyKeyboardRemove>) {
    ReplyKeyboardRemove obj{};
    obj.remove_keyboard = ParseComplex<OptionalTrue>(value["remove_keyboard"]);
    obj.selective = ParseComplex<Optional<Boolean>>(value["selective"]);
    return obj;
}

}  // namespace tg
