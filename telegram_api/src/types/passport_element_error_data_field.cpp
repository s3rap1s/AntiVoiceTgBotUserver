#include <tg/types/passport_element_error_data_field.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

PassportElementErrorDataField Parse(const Value& value, To<PassportElementErrorDataField>) {
    PassportElementErrorDataField obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.field_name = ParseComplex<String>(value["field_name"]);
    obj.data_hash = ParseComplex<String>(value["data_hash"]);
    obj.message = ParseComplex<String>(value["message"]);
    return obj;
}

void Serialize(const PassportElementErrorDataField& obj, ValueBuilder& builder) {
    internal::Put(builder, "source", obj.source);
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "field_name", obj.field_name);
    internal::Put(builder, "data_hash", obj.data_hash);
    internal::Put(builder, "message", obj.message);
}

}  // namespace tg
