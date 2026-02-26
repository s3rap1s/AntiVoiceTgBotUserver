#pragma once

#include "common.hpp"

namespace tg {

struct PassportElementErrorFile {
    String source;
    String type;
    String file_hash;
    String message;
};

PassportElementErrorFile Parse(const Value& value,
                               To<PassportElementErrorFile>);

}  // namespace tg
