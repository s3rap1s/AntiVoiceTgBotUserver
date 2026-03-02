#include <types/dice.hpp>

#include "common.hpp"

namespace tg {

Dice Parse(const Value& value, To<Dice>) {
    Dice obj{};
    obj.emoji = ParseComplex<String>(value["emoji"]);
    obj.value = ParseComplex<Integer>(value["value"]);
    return obj;
}

}  // namespace tg
