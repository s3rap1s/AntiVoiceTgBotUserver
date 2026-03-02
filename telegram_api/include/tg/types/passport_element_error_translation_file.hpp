#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct PassportElementErrorTranslationFile {
    String source;
    String type;
    String file_hash;
    String message;
};

PassportElementErrorTranslationFile Parse(
    const Value& value, To<PassportElementErrorTranslationFile>);

}  // namespace tg
