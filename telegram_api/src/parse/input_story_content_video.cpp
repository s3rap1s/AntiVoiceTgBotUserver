#include <tg/types/input_story_content_video.hpp>

#include "common.hpp"

namespace tg {

InputStoryContentVideo Parse(const Value& value, To<InputStoryContentVideo>) {
    InputStoryContentVideo obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.video = ParseComplex<String>(value["video"]);
    obj.duration = ParseComplex<Optional<Float>>(value["duration"]);
    obj.main_frame_timestamp =
        ParseComplex<Optional<Float>>(value["main_frame_timestamp"]);
    obj.is_animation = ParseComplex<Optional<Boolean>>(value["is_animation"]);
    return obj;
}

}  // namespace tg
