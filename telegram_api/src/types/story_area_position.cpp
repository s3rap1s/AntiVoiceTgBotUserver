#include <tg/types/story_area_position.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

StoryAreaPosition Parse(const Value& value, To<StoryAreaPosition>) {
    StoryAreaPosition obj{};
    obj.x_percentage = ParseComplex<Float>(value["x_percentage"]);
    obj.y_percentage = ParseComplex<Float>(value["y_percentage"]);
    obj.width_percentage = ParseComplex<Float>(value["width_percentage"]);
    obj.height_percentage = ParseComplex<Float>(value["height_percentage"]);
    obj.rotation_angle = ParseComplex<Float>(value["rotation_angle"]);
    obj.corner_radius_percentage = ParseComplex<Float>(value["corner_radius_percentage"]);
    return obj;
}

void Serialize(const StoryAreaPosition& obj, ValueBuilder& builder) {
    internal::Put(builder, "x_percentage", obj.x_percentage);
    internal::Put(builder, "y_percentage", obj.y_percentage);
    internal::Put(builder, "width_percentage", obj.width_percentage);
    internal::Put(builder, "height_percentage", obj.height_percentage);
    internal::Put(builder, "rotation_angle", obj.rotation_angle);
    internal::Put(builder, "corner_radius_percentage", obj.corner_radius_percentage);
}

}  // namespace tg
