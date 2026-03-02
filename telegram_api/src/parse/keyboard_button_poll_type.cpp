#include <types/keyboard_button_poll_type.hpp>

#include "common.hpp"

namespace tg {

KeyboardButtonPollType Parse(const Value& value, To<KeyboardButtonPollType>) {
    KeyboardButtonPollType obj{};
    obj.type = ParseComplex<Optional<String>>(value["type"]);
    return obj;
}

}  // namespace tg
