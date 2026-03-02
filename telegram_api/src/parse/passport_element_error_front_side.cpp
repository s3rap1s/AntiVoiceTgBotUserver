#include <types/passport_element_error_front_side.hpp>

#include "common.hpp"

namespace tg {

PassportElementErrorFrontSide Parse(const Value& value,
                                    To<PassportElementErrorFrontSide>) {
    PassportElementErrorFrontSide obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.file_hash = ParseComplex<String>(value["file_hash"]);
    obj.message = ParseComplex<String>(value["message"]);
    return obj;
}

}  // namespace tg
