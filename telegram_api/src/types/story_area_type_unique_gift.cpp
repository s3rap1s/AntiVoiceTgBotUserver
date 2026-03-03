#include <tg/types/story_area_type_unique_gift.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

StoryAreaTypeUniqueGift Parse(const Value& value, To<StoryAreaTypeUniqueGift>) {
    StoryAreaTypeUniqueGift obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.name = ParseComplex<String>(value["name"]);
    return obj;
}

void Serialize(const StoryAreaTypeUniqueGift& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "name", obj.name);
}

}  // namespace tg
