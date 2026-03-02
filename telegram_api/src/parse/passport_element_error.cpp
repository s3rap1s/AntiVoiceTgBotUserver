#include <tg/types/passport_element_error.hpp>
#include <tg/types/passport_element_error_data_field.hpp>
#include <tg/types/passport_element_error_file.hpp>
#include <tg/types/passport_element_error_files.hpp>
#include <tg/types/passport_element_error_front_side.hpp>
#include <tg/types/passport_element_error_reverse_side.hpp>
#include <tg/types/passport_element_error_selfie.hpp>
#include <tg/types/passport_element_error_translation_file.hpp>
#include <tg/types/passport_element_error_translation_files.hpp>
#include <tg/types/passport_element_error_unspecified.hpp>

#include "common.hpp"

namespace tg {

PassportElementError Parse(const Value& value, To<PassportElementError>) {
    const auto source = ParseComplex<String>(value["source"]);
    if (source == "data")
        return ParseComplex<PassportElementErrorDataField>(value);
    if (source == "front_side")
        return ParseComplex<PassportElementErrorFrontSide>(value);
    if (source == "reverse_side")
        return ParseComplex<PassportElementErrorReverseSide>(value);
    if (source == "selfie")
        return ParseComplex<PassportElementErrorSelfie>(value);
    if (source == "file") return ParseComplex<PassportElementErrorFile>(value);
    if (source == "files")
        return ParseComplex<PassportElementErrorFiles>(value);
    if (source == "translation_file")
        return ParseComplex<PassportElementErrorTranslationFile>(value);
    if (source == "translation_files")
        return ParseComplex<PassportElementErrorTranslationFiles>(value);
    if (source == "unspecified")
        return ParseComplex<PassportElementErrorUnspecified>(value);
    throw std::runtime_error("Unknown PassportElementError source: " + source);
}

}  // namespace tg
