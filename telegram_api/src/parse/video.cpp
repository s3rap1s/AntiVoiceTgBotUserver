#include <types/photo_size.hpp>
#include <types/video.hpp>
#include <types/video_quality.hpp>

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
    obj.start_timestamp =
        ParseComplex<Optional<Integer>>(value["start_timestamp"]);
    obj.qualities =
        ParseComplex<Optional<Array<VideoQuality>>>(value["qualities"]);
    obj.file_name = ParseComplex<Optional<String>>(value["file_name"]);
    obj.mime_type = ParseComplex<Optional<String>>(value["mime_type"]);
    obj.file_size = ParseComplex<Optional<Integer>>(value["file_size"]);
    return obj;
}

}  // namespace tg
