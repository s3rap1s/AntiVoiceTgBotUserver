#include <tg/types/audio.hpp>
#include <tg/types/photo_size.hpp>

#include "../internal/json_builder.hpp"
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

void Serialize(const Audio& obj, ValueBuilder& builder) {
    internal::Put(builder, "file_id", obj.file_id);
    internal::Put(builder, "file_unique_id", obj.file_unique_id);
    internal::Put(builder, "duration", obj.duration);
    internal::Put(builder, "performer", obj.performer);
    internal::Put(builder, "title", obj.title);
    internal::Put(builder, "file_name", obj.file_name);
    internal::Put(builder, "mime_type", obj.mime_type);
    internal::Put(builder, "file_size", obj.file_size);
    internal::Put(builder, "thumbnail", obj.thumbnail);
}

}  // namespace tg
