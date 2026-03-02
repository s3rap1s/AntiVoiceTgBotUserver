#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct PassportElementErrorTranslationFiles {
    String source;
    String type;
    Array<String> file_hashes;
    String message;
};

PassportElementErrorTranslationFiles Parse(
    const Value& value, To<PassportElementErrorTranslationFiles>);

}  // namespace tg
