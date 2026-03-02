#pragma once

#include <types/common.hpp>

namespace tg {

struct SuggestedPostPrice {
    String currency;
    Integer amount;
};

SuggestedPostPrice Parse(const Value& value, To<SuggestedPostPrice>);

}  // namespace tg
