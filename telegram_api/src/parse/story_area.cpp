#include <types/story_area.hpp>
#include <types/story_area_position.hpp>
#include <types/story_area_type.hpp>

#include "common.hpp"

namespace tg {

StoryArea Parse(const Value& value, To<StoryArea>) {
    StoryArea obj{};
    obj.position = ParseComplex<StoryAreaPosition>(value["position"]);
    obj.type = ParseComplex<StoryAreaType>(value["type"]);
    return obj;
}

}  // namespace tg
