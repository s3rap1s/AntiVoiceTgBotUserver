#pragma once

#include "common.hpp"

namespace tg {

struct StoryAreaPosition {
    Float x_percentage;
    Float y_percentage;
    Float width_percentage;
    Float height_percentage;
    Float rotation_angle;
    Float corner_radius_percentage;
};

StoryAreaPosition Parse(const Value& value, To<StoryAreaPosition>);

}  // namespace tg
