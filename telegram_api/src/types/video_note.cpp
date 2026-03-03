#include <tg/types/photo_size.hpp>
#include <tg/types/video_note.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

VideoNote Parse(const Value& value, To<VideoNote>) {
    VideoNote obj{};
    obj.file_id = ParseComplex<String>(value["file_id"]);
    obj.file_unique_id = ParseComplex<String>(value["file_unique_id"]);
    obj.length = ParseComplex<Integer>(value["length"]);
    obj.duration = ParseComplex<Integer>(value["duration"]);
    obj.thumbnail = ParseComplex<Optional<PhotoSize>>(value["thumbnail"]);
    obj.file_size = ParseComplex<Optional<Integer>>(value["file_size"]);
    return obj;
}

void Serialize(const VideoNote& obj, ValueBuilder& builder) {
    internal::Put(builder, "file_id", obj.file_id);
    internal::Put(builder, "file_unique_id", obj.file_unique_id);
    internal::Put(builder, "length", obj.length);
    internal::Put(builder, "duration", obj.duration);
    internal::Put(builder, "thumbnail", obj.thumbnail);
    internal::Put(builder, "file_size", obj.file_size);
}

}  // namespace tg
