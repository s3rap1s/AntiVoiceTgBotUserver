#include <tg/types/keyboard_button_poll_type.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

KeyboardButtonPollType Parse(const Value& value, To<KeyboardButtonPollType>) {
    KeyboardButtonPollType obj{};
    obj.type = ParseComplex<Optional<String>>(value["type"]);
    return obj;
}

void Serialize(const KeyboardButtonPollType& obj, ValueBuilder& builder) { internal::Put(builder, "type", obj.type); }

}  // namespace tg
