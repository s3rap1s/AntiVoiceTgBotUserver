#include <tg/types/audio.hpp>
#include <tg/types/photo_size.hpp>

#include "common.hpp"

namespace tg {

Audio Parse(const Value& value, To<Audio>) {
    Audio obj{};
    obj.file_id = ParseComplex<String>(value["file_id"]);
    obj.file_unique_id = ParseComplex<String>(value["file_unique_id"]);
    obj.duration = ParseComplex<Integer>(value["duration"]);
    obj.performer = ParseComplex<Optional<String>>(value["performer"]);
    obj.title = ParseComplex<Optional<String>>(value["title"]);
    obj.file_name = ParseComplex<Optional<String>>(value["file_name"]);
    obj.mime_type = ParseComplex<Optional<String>>(value["mime_type"]);
    obj.file_size = ParseComplex<Optional<Integer>>(value["file_size"]);
    obj.thumbnail = ParseComplex<Optional<PhotoSize>>(value["thumbnail"]);
    return obj;
}

}  // namespace tg
