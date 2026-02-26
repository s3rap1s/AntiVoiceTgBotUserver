#pragma once

#include "common.hpp"

namespace tg {

struct PassportElementErrorFrontSide {
    String source;
    String type;
    String file_hash;
    String message;
};

PassportElementErrorFrontSide Parse(const Value& value,
                                    To<PassportElementErrorFrontSide>);

}  // namespace tg
