#include <tg/types/passport_element_error_reverse_side.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

PassportElementErrorReverseSide Parse(const Value& value, To<PassportElementErrorReverseSide>) {
    PassportElementErrorReverseSide obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.file_hash = ParseComplex<String>(value["file_hash"]);
    obj.message = ParseComplex<String>(value["message"]);
    return obj;
}

void Serialize(const PassportElementErrorReverseSide& obj, ValueBuilder& builder) {
    internal::Put(builder, "source", obj.source);
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "file_hash", obj.file_hash);
    internal::Put(builder, "message", obj.message);
}

}  // namespace tg
