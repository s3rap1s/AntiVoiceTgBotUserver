#pragma once

#include <types/common.hpp>

namespace tg {

struct BackgroundFillSolid {
    String type;
    Integer color;
};

BackgroundFillSolid Parse(const Value& value, To<BackgroundFillSolid>);

}  // namespace tg
