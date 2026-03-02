#include <types/passport_element_error_translation_files.hpp>

#include "common.hpp"

namespace tg {

PassportElementErrorTranslationFiles Parse(
    const Value& value, To<PassportElementErrorTranslationFiles>) {
    PassportElementErrorTranslationFiles obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.file_hashes = ParseComplex<Array<String>>(value["file_hashes"]);
    obj.message = ParseComplex<String>(value["message"]);
    return obj;
}

}  // namespace tg
