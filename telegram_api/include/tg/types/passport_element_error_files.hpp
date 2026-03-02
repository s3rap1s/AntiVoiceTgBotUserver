#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct PassportElementErrorFiles {
    String source;
    String type;
    Array<String> file_hashes;
    String message;
};

PassportElementErrorFiles Parse(const Value& value,
                                To<PassportElementErrorFiles>);

}  // namespace tg
