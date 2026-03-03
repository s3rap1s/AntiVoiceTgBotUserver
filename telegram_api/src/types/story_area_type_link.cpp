#include <tg/types/story_area_type_link.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

StoryAreaTypeLink Parse(const Value& value, To<StoryAreaTypeLink>) {
    StoryAreaTypeLink obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.url = ParseComplex<String>(value["url"]);
    return obj;
}

void Serialize(const StoryAreaTypeLink& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "url", obj.url);
}

}  // namespace tg
