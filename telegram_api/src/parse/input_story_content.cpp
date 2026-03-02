#include <tg/types/input_story_content.hpp>
#include <tg/types/input_story_content_photo.hpp>
#include <tg/types/input_story_content_video.hpp>

#include "common.hpp"

namespace tg {

InputStoryContent Parse(const Value& value, To<InputStoryContent>) {
    if (detail::IsPresent(value["photo"]))
        return ParseComplex<InputStoryContentPhoto>(value);
    if (detail::IsPresent(value["video"]))
        return ParseComplex<InputStoryContentVideo>(value);
    throw std::runtime_error("Unknown InputStoryContent payload");
}

}  // namespace tg
