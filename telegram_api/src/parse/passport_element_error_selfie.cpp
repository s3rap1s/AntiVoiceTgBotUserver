#include <types/passport_element_error_selfie.hpp>

#include "common.hpp"

namespace tg {

PassportElementErrorSelfie Parse(const Value& value,
                                 To<PassportElementErrorSelfie>) {
    PassportElementErrorSelfie obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.file_hash = ParseComplex<String>(value["file_hash"]);
    obj.message = ParseComplex<String>(value["message"]);
    return obj;
}

}  // namespace tg
