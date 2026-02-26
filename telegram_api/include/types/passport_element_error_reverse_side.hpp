#pragma once

#include "common.hpp"

namespace tg {

struct PassportElementErrorReverseSide {
    String source;
    String type;
    String file_hash;
    String message;
};

PassportElementErrorReverseSide Parse(const Value& value,
                                      To<PassportElementErrorReverseSide>);

}  // namespace tg
