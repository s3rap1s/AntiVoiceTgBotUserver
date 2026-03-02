#pragma once

#include <types/common.hpp>
#include <types/input_story_content_photo.hpp>
#include <types/input_story_content_video.hpp>

namespace tg {

using InputStoryContent = OneOf<InputStoryContentPhoto, InputStoryContentVideo>;

InputStoryContent Parse(const Value& value, To<InputStoryContent>);

}  // namespace tg
