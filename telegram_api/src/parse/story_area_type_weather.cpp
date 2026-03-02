#include <types/story_area_type_weather.hpp>

#include "common.hpp"

namespace tg {

StoryAreaTypeWeather Parse(const Value& value, To<StoryAreaTypeWeather>) {
    StoryAreaTypeWeather obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.temperature = ParseComplex<Float>(value["temperature"]);
    obj.emoji = ParseComplex<String>(value["emoji"]);
    obj.background_color = ParseComplex<Integer>(value["background_color"]);
    return obj;
}

}  // namespace tg
