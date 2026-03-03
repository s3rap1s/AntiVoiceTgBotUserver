#include <tg/types/input_story_content_photo.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputStoryContentPhoto Parse(const Value& value, To<InputStoryContentPhoto>) {
    InputStoryContentPhoto obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.photo = ParseComplex<String>(value["photo"]);
    return obj;
}

void Serialize(const InputStoryContentPhoto& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "photo", obj.photo);
}

}  // namespace tg
