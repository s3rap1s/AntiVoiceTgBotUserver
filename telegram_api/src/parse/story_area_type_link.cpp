#include <types/story_area_type_link.hpp>

#include "common.hpp"

namespace tg {

StoryAreaTypeLink Parse(const Value& value, To<StoryAreaTypeLink>) {
    StoryAreaTypeLink obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.url = ParseComplex<String>(value["url"]);
    return obj;
}

}  // namespace tg
