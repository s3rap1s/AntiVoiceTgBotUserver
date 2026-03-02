#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct PassportElementErrorUnspecified {
    String source;
    String type;
    String element_hash;
    String message;
};

PassportElementErrorUnspecified Parse(const Value& value,
                                      To<PassportElementErrorUnspecified>);

}  // namespace tg
