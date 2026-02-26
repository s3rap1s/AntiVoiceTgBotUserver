#pragma once

#include "common.hpp"

namespace tg {

struct StoryAreaTypeWeather {
    String type;
    Float temperature;
    String emoji;
    Integer background_color;
};

StoryAreaTypeWeather Parse(const Value& value, To<StoryAreaTypeWeather>);

}  // namespace tg
