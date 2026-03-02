#include <tg/types/story_area_type_unique_gift.hpp>

#include "common.hpp"

namespace tg {

StoryAreaTypeUniqueGift Parse(const Value& value, To<StoryAreaTypeUniqueGift>) {
    StoryAreaTypeUniqueGift obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.name = ParseComplex<String>(value["name"]);
    return obj;
}

}  // namespace tg
