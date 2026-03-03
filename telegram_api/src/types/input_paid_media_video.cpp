#include <tg/types/input_paid_media_video.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputPaidMediaVideo Parse(const Value& value, To<InputPaidMediaVideo>) {
    InputPaidMediaVideo obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.media = ParseComplex<String>(value["media"]);
    obj.thumbnail = ParseComplex<Optional<String>>(value["thumbnail"]);
    obj.cover = ParseComplex<Optional<String>>(value["cover"]);
    obj.start_timestamp = ParseComplex<Optional<Integer>>(value["start_timestamp"]);
    obj.width = ParseComplex<Optional<Integer>>(value["width"]);
    obj.height = ParseComplex<Optional<Integer>>(value["height"]);
    obj.duration = ParseComplex<Optional<Integer>>(value["duration"]);
    obj.supports_streaming = ParseComplex<Optional<Boolean>>(value["supports_streaming"]);
    return obj;
}

void Serialize(const InputPaidMediaVideo& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "media", obj.media);
    internal::Put(builder, "thumbnail", obj.thumbnail);
    internal::Put(builder, "cover", obj.cover);
    internal::Put(builder, "start_timestamp", obj.start_timestamp);
    internal::Put(builder, "width", obj.width);
    internal::Put(builder, "height", obj.height);
    internal::Put(builder, "duration", obj.duration);
    internal::Put(builder, "supports_streaming", obj.supports_streaming);
}

}  // namespace tg
