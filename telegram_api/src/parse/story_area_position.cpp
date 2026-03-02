#include <tg/types/story_area_position.hpp>

#include "common.hpp"

namespace tg {

StoryAreaPosition Parse(const Value& value, To<StoryAreaPosition>) {
    StoryAreaPosition obj{};
    obj.x_percentage = ParseComplex<Float>(value["x_percentage"]);
    obj.y_percentage = ParseComplex<Float>(value["y_percentage"]);
    obj.width_percentage = ParseComplex<Float>(value["width_percentage"]);
    obj.height_percentage = ParseComplex<Float>(value["height_percentage"]);
    obj.rotation_angle = ParseComplex<Float>(value["rotation_angle"]);
    obj.corner_radius_percentage =
        ParseComplex<Float>(value["corner_radius_percentage"]);
    return obj;
}

}  // namespace tg
