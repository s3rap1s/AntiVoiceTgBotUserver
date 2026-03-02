#include <tg/types/passport_element_error_reverse_side.hpp>

#include "common.hpp"

namespace tg {

PassportElementErrorReverseSide Parse(const Value& value,
                                      To<PassportElementErrorReverseSide>) {
    PassportElementErrorReverseSide obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.file_hash = ParseComplex<String>(value["file_hash"]);
    obj.message = ParseComplex<String>(value["message"]);
    return obj;
}

}  // namespace tg
