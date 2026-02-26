#pragma once

#include "common.hpp"

namespace tg {

struct InputProfilePhotoStatic {
    String type;
    String string;
};

InputProfilePhotoStatic Parse(const Value& value, To<InputProfilePhotoStatic>);

}  // namespace tg
