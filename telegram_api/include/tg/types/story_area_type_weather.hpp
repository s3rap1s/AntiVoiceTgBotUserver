#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct StoryAreaTypeWeather {
    String type;
    Float temperature;
    String emoji;
    Integer background_color;
};

StoryAreaTypeWeather Parse(const Value& value, To<StoryAreaTypeWeather>);

void Serialize(const StoryAreaTypeWeather& obj, ValueBuilder& builder);

}  // namespace tg
