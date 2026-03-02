#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct PassportElementErrorSelfie {
    String source;
    String type;
    String file_hash;
    String message;
};

PassportElementErrorSelfie Parse(const Value& value,
                                 To<PassportElementErrorSelfie>);

}  // namespace tg
