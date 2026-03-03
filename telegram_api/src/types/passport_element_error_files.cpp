#include <tg/types/passport_element_error_files.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

PassportElementErrorFiles Parse(const Value& value, To<PassportElementErrorFiles>) {
    PassportElementErrorFiles obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.file_hashes = ParseComplex<Array<String>>(value["file_hashes"]);
    obj.message = ParseComplex<String>(value["message"]);
    return obj;
}

void Serialize(const PassportElementErrorFiles& obj, ValueBuilder& builder) {
    internal::Put(builder, "source", obj.source);
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "file_hashes", obj.file_hashes);
    internal::Put(builder, "message", obj.message);
}

}  // namespace tg
