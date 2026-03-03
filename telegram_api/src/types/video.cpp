#include <tg/types/photo_size.hpp>
#include <tg/types/video.hpp>
#include <tg/types/video_quality.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

Video Parse(const Value& value, To<Video>) {
    Video obj{};
    obj.file_id = ParseComplex<String>(value["file_id"]);
    obj.file_unique_id = ParseComplex<String>(value["file_unique_id"]);
    obj.width = ParseComplex<Integer>(value["width"]);
    obj.height = ParseComplex<Integer>(value["height"]);
    obj.duration = ParseComplex<Integer>(value["duration"]);
    obj.thumbnail = ParseComplex<Optional<PhotoSize>>(value["thumbnail"]);
    obj.cover = ParseComplex<Optional<Array<PhotoSize>>>(value["cover"]);
    obj.start_timestamp = ParseComplex<Optional<Integer>>(value["start_timestamp"]);
    obj.qualities = ParseComplex<Optional<Array<VideoQuality>>>(value["qualities"]);
    obj.file_name = ParseComplex<Optional<String>>(value["file_name"]);
    obj.mime_type = ParseComplex<Optional<String>>(value["mime_type"]);
    obj.file_size = ParseComplex<Optional<Integer>>(value["file_size"]);
    return obj;
}

void Serialize(const Video& obj, ValueBuilder& builder) {
    internal::Put(builder, "file_id", obj.file_id);
    internal::Put(builder, "file_unique_id", obj.file_unique_id);
    internal::Put(builder, "width", obj.width);
    internal::Put(builder, "height", obj.height);
    internal::Put(builder, "duration", obj.duration);
    internal::Put(builder, "thumbnail", obj.thumbnail);
    internal::Put(builder, "cover", obj.cover);
    internal::Put(builder, "start_timestamp", obj.start_timestamp);
    internal::Put(builder, "qualities", obj.qualities);
    internal::Put(builder, "file_name", obj.file_name);
    internal::Put(builder, "mime_type", obj.mime_type);
    internal::Put(builder, "file_size", obj.file_size);
}

}  // namespace tg
