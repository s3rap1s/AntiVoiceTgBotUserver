#include <tg/types/story_area.hpp>
#include <tg/types/story_area_position.hpp>
#include <tg/types/story_area_type.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

StoryArea Parse(const Value& value, To<StoryArea>) {
    StoryArea obj{};
    obj.position = ParseComplex<StoryAreaPosition>(value["position"]);
    obj.type = ParseComplex<StoryAreaType>(value["type"]);
    return obj;
}

void Serialize(const StoryArea& obj, ValueBuilder& builder) {
    internal::Put(builder, "position", obj.position);
    internal::Put(builder, "type", obj.type);
}

}  // namespace tg
