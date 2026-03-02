#include <tg/types/passport_element_error_data_field.hpp>

#include "common.hpp"

namespace tg {

PassportElementErrorDataField Parse(const Value& value,
                                    To<PassportElementErrorDataField>) {
    PassportElementErrorDataField obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.field_name = ParseComplex<String>(value["field_name"]);
    obj.data_hash = ParseComplex<String>(value["data_hash"]);
    obj.message = ParseComplex<String>(value["message"]);
    return obj;
}

}  // namespace tg
