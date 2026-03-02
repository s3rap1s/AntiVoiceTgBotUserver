#pragma once

#include <tg/types/common.hpp>
#include <tg/types/gift.hpp>

namespace tg {

struct Gifts {
    Array<Gift> gifts;
};

Gifts Parse(const Value& value, To<Gifts>);

}  // namespace tg
