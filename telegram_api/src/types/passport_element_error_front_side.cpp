#include <tg/types/passport_element_error_front_side.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

PassportElementErrorFrontSide Parse(const Value& value, To<PassportElementErrorFrontSide>) {
    PassportElementErrorFrontSide obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.file_hash = ParseComplex<String>(value["file_hash"]);
    obj.message = ParseComplex<String>(value["message"]);
    return obj;
}

void Serialize(const PassportElementErrorFrontSide& obj, ValueBuilder& builder) {
    internal::Put(builder, "source", obj.source);
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "file_hash", obj.file_hash);
    internal::Put(builder, "message", obj.message);
}

}  // namespace tg
