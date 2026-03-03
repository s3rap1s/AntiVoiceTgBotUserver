#include <tg/types/story_area_type_weather.hpp>

#include "../internal/json_builder.hpp"
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

void Serialize(const StoryAreaTypeWeather& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "temperature", obj.temperature);
    internal::Put(builder, "emoji", obj.emoji);
    internal::Put(builder, "background_color", obj.background_color);
}

}  // namespace tg
