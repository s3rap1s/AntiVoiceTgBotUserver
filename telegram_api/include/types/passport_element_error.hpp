#pragma once

#include <types/common.hpp>
#include <types/passport_element_error_data_field.hpp>
#include <types/passport_element_error_file.hpp>
#include <types/passport_element_error_files.hpp>
#include <types/passport_element_error_front_side.hpp>
#include <types/passport_element_error_reverse_side.hpp>
#include <types/passport_element_error_selfie.hpp>
#include <types/passport_element_error_translation_file.hpp>
#include <types/passport_element_error_translation_files.hpp>
#include <types/passport_element_error_unspecified.hpp>

namespace tg {

using PassportElementError =
    OneOf<PassportElementErrorDataField, PassportElementErrorFrontSide,
          PassportElementErrorReverseSide, PassportElementErrorSelfie,
          PassportElementErrorFile, PassportElementErrorFiles,
          PassportElementErrorTranslationFile,
          PassportElementErrorTranslationFiles,
          PassportElementErrorUnspecified>;

PassportElementError Parse(const Value& value, To<PassportElementError>);

}  // namespace tg
