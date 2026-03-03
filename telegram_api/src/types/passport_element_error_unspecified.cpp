#include <tg/types/passport_element_error_unspecified.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

PassportElementErrorUnspecified Parse(const Value& value, To<PassportElementErrorUnspecified>) {
    PassportElementErrorUnspecified obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.element_hash = ParseComplex<String>(value["element_hash"]);
    obj.message = ParseComplex<String>(value["message"]);
    return obj;
}

void Serialize(const PassportElementErrorUnspecified& obj, ValueBuilder& builder) {
    internal::Put(builder, "source", obj.source);
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "element_hash", obj.element_hash);
    internal::Put(builder, "message", obj.message);
}

}  // namespace tg
