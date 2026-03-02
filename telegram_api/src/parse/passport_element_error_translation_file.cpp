#include <types/passport_element_error_translation_file.hpp>

#include "common.hpp"

namespace tg {

PassportElementErrorTranslationFile Parse(
    const Value& value, To<PassportElementErrorTranslationFile>) {
    PassportElementErrorTranslationFile obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.file_hash = ParseComplex<String>(value["file_hash"]);
    obj.message = ParseComplex<String>(value["message"]);
    return obj;
}

}  // namespace tg
