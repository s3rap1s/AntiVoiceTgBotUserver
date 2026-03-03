#include <tg/types/dice.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

Dice Parse(const Value& value, To<Dice>) {
    Dice obj{};
    obj.emoji = ParseComplex<String>(value["emoji"]);
    obj.value = ParseComplex<Integer>(value["value"]);
    return obj;
}

void Serialize(const Dice& obj, ValueBuilder& builder) {
    internal::Put(builder, "emoji", obj.emoji);
    internal::Put(builder, "value", obj.value);
}

}  // namespace tg
