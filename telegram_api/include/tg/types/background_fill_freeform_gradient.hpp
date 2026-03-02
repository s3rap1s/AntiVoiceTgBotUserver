#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct BackgroundFillFreeformGradient {
    String type;
    Array<Integer> color;
};

BackgroundFillFreeformGradient Parse(const Value& value,
                                     To<BackgroundFillFreeformGradient>);

}  // namespace tg
