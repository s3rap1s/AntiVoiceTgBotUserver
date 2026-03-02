#pragma once

#include <tg/types/background_fill.hpp>
#include <tg/types/common.hpp>

namespace tg {

struct BackgroundTypeFill {
    String type;
    BackgroundFill fill;
    Integer dark_theme_dimming;
};

BackgroundTypeFill Parse(const Value& value, To<BackgroundTypeFill>);

}  // namespace tg
