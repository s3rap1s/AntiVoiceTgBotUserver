#pragma once

#include <types/common.hpp>

namespace tg {

struct LabeledPrice {
    String label;
    Integer amount;
};

LabeledPrice Parse(const Value& value, To<LabeledPrice>);

}  // namespace tg
