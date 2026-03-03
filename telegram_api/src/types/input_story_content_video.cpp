#include <tg/types/input_story_content_video.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputStoryContentVideo Parse(const Value& value, To<InputStoryContentVideo>) {
    InputStoryContentVideo obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.video = ParseComplex<String>(value["video"]);
    obj.duration = ParseComplex<Optional<Float>>(value["duration"]);
    obj.main_frame_timestamp = ParseComplex<Optional<Float>>(value["main_frame_timestamp"]);
    obj.is_animation = ParseComplex<Optional<Boolean>>(value["is_animation"]);
    return obj;
}

void Serialize(const InputStoryContentVideo& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "video", obj.video);
    internal::Put(builder, "duration", obj.duration);
    internal::Put(builder, "main_frame_timestamp", obj.main_frame_timestamp);
    internal::Put(builder, "is_animation", obj.is_animation);
}

}  // namespace tg
