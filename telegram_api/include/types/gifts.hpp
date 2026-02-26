#pragma once

#include "common.hpp"
#include "gift.hpp"

namespace tg {

struct Gifts {
    Array<Gift> gifts;
};

Gifts Parse(const Value& value, To<Gifts>);

}  // namespace tg
