#include <types/passport_element_error_unspecified.hpp>

#include "common.hpp"

namespace tg {

PassportElementErrorUnspecified Parse(const Value& value,
                                      To<PassportElementErrorUnspecified>) {
    PassportElementErrorUnspecified obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.element_hash = ParseComplex<String>(value["element_hash"]);
    obj.message = ParseComplex<String>(value["message"]);
    return obj;
}

}  // namespace tg
