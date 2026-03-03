#include <tg/types/input_story_content.hpp>
#include <tg/types/input_story_content_photo.hpp>
#include <tg/types/input_story_content_video.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputStoryContent Parse(const Value& value, To<InputStoryContent>) {
    if (internal::IsPresent(value["photo"])) return ParseComplex<InputStoryContentPhoto>(value);
    if (internal::IsPresent(value["video"])) return ParseComplex<InputStoryContentVideo>(value);
    throw std::runtime_error("Unknown InputStoryContent payload");
}

void Serialize(const InputStoryContent& obj, ValueBuilder& builder) { internal::Set(builder, obj); }

}  // namespace tg
