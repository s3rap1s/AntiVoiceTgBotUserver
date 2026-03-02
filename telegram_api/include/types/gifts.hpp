#pragma once

#include <types/common.hpp>
#include <types/gift.hpp>

namespace tg {

struct Gifts {
    Array<Gift> gifts;
};

Gifts Parse(const Value& value, To<Gifts>);

}  // namespace tg
