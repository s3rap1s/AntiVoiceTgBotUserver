#pragma once

#include <types/background_fill.hpp>
#include <types/common.hpp>

namespace tg {

struct BackgroundTypeFill {
    String type;
    BackgroundFill fill;
    Integer dark_theme_dimming;
};

BackgroundTypeFill Parse(const Value& value, To<BackgroundTypeFill>);

}  // namespace tg
