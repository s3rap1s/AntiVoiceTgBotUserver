#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct BackgroundFillGradient {
    String type;
    Integer top_color;
    Integer bottom_color;
    Integer rotation_angle;
};

BackgroundFillGradient Parse(const Value& value, To<BackgroundFillGradient>);

}  // namespace tg
