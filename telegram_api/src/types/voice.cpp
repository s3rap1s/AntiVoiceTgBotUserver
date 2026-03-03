#include <tg/types/voice.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

Voice Parse(const Value& value, To<Voice>) {
    Voice obj{};
    obj.file_id = ParseComplex<String>(value["file_id"]);
    obj.file_unique_id = ParseComplex<String>(value["file_unique_id"]);
    obj.duration = ParseComplex<Integer>(value["duration"]);
    obj.mime_type = ParseComplex<Optional<String>>(value["mime_type"]);
    obj.file_size = ParseComplex<Optional<Integer>>(value["file_size"]);
    return obj;
}

void Serialize(const Voice& obj, ValueBuilder& builder) {
    internal::Put(builder, "file_id", obj.file_id);
    internal::Put(builder, "file_unique_id", obj.file_unique_id);
    internal::Put(builder, "duration", obj.duration);
    internal::Put(builder, "mime_type", obj.mime_type);
    internal::Put(builder, "file_size", obj.file_size);
}

}  // namespace tg
