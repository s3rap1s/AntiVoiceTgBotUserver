#include <tg/types/video_quality.hpp>

#include "common.hpp"

namespace tg {

VideoQuality Parse(const Value& value, To<VideoQuality>) {
    VideoQuality obj{};
    obj.file_id = ParseComplex<String>(value["file_id"]);
    obj.file_unique_id = ParseComplex<String>(value["file_unique_id"]);
    obj.width = ParseComplex<Integer>(value["width"]);
    obj.height = ParseComplex<Integer>(value["height"]);
    obj.codec = ParseComplex<String>(value["codec"]);
    obj.file_size = ParseComplex<Optional<Integer>>(value["file_size"]);
    return obj;
}

}  // namespace tg
