#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/input_story_content_photo.hpp>
#include <tg/types/input_story_content_video.hpp>

namespace tg {

using InputStoryContent = OneOf<InputStoryContentPhoto, InputStoryContentVideo>;

InputStoryContent Parse(const Value& value, To<InputStoryContent>);

void Serialize(const InputStoryContent& obj, ValueBuilder& builder);

}  // namespace tg
