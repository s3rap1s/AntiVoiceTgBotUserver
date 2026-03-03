#include <tg/types/document.hpp>
#include <tg/types/photo_size.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

Document Parse(const Value& value, To<Document>) {
    Document obj{};
    obj.file_id = ParseComplex<String>(value["file_id"]);
    obj.file_unique_id = ParseComplex<String>(value["file_unique_id"]);
    obj.thumbnail = ParseComplex<Optional<PhotoSize>>(value["thumbnail"]);
    obj.file_name = ParseComplex<Optional<String>>(value["file_name"]);
    obj.mime_type = ParseComplex<Optional<String>>(value["mime_type"]);
    obj.file_size = ParseComplex<Optional<Integer>>(value["file_size"]);
    return obj;
}

void Serialize(const Document& obj, ValueBuilder& builder) {
    internal::Put(builder, "file_id", obj.file_id);
    internal::Put(builder, "file_unique_id", obj.file_unique_id);
    internal::Put(builder, "thumbnail", obj.thumbnail);
    internal::Put(builder, "file_name", obj.file_name);
    internal::Put(builder, "mime_type", obj.mime_type);
    internal::Put(builder, "file_size", obj.file_size);
}

}  // namespace tg
