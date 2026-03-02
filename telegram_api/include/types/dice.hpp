#pragma once

#include <types/common.hpp>

namespace tg {

struct Dice {
    String emoji;
    Integer value;
};

Dice Parse(const Value& value, To<Dice>);

}  // namespace tg
