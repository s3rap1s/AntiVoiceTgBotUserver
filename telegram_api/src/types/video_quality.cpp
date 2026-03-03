#include <tg/types/video_quality.hpp>

#include "../internal/json_builder.hpp"
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

void Serialize(const VideoQuality& obj, ValueBuilder& builder) {
    internal::Put(builder, "file_id", obj.file_id);
    internal::Put(builder, "file_unique_id", obj.file_unique_id);
    internal::Put(builder, "width", obj.width);
    internal::Put(builder, "height", obj.height);
    internal::Put(builder, "codec", obj.codec);
    internal::Put(builder, "file_size", obj.file_size);
}

}  // namespace tg
