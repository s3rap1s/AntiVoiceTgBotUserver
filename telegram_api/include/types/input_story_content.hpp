#pragma once

#include "common.hpp"
#include "input_story_content_photo.hpp"
#include "input_story_content_video.hpp"

namespace tg {

using InputStoryContent = OneOf<InputStoryContentPhoto, InputStoryContentVideo>;

InputStoryContent Parse(const Value& value, To<InputStoryContent>);

}  // namespace tg
