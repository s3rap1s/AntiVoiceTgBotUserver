#include <types/photo_size.hpp>
#include <types/video_note.hpp>

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

}  // namespace tg
