#pragma once

#include "common.hpp"

namespace tg {

struct GiftBackground {
    Integer center_color;
    Integer edge_color;
    Integer text_color;
};

GiftBackground Parse(const Value& value, To<GiftBackground>);

}  // namespace tg
