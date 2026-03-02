#include <types/input_story_content_photo.hpp>

#include "common.hpp"

namespace tg {

InputStoryContentPhoto Parse(const Value& value, To<InputStoryContentPhoto>) {
    InputStoryContentPhoto obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.photo = ParseComplex<String>(value["photo"]);
    return obj;
}

}  // namespace tg
