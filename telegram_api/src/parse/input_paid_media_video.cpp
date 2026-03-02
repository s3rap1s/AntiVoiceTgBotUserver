#include <types/input_paid_media_video.hpp>

#include "common.hpp"

namespace tg {

InputPaidMediaVideo Parse(const Value& value, To<InputPaidMediaVideo>) {
    InputPaidMediaVideo obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.media = ParseComplex<String>(value["media"]);
    obj.thumbnail = ParseComplex<Optional<String>>(value["thumbnail"]);
    obj.cover = ParseComplex<Optional<String>>(value["cover"]);
    obj.start_timestamp =
        ParseComplex<Optional<Integer>>(value["start_timestamp"]);
    obj.width = ParseComplex<Optional<Integer>>(value["width"]);
    obj.height = ParseComplex<Optional<Integer>>(value["height"]);
    obj.duration = ParseComplex<Optional<Integer>>(value["duration"]);
    obj.supports_streaming =
        ParseComplex<Optional<Boolean>>(value["supports_streaming"]);
    return obj;
}

}  // namespace tg
