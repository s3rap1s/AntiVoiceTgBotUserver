#pragma once

#include <types/common.hpp>

namespace tg {

struct InputProfilePhotoStatic {
    String type;
    String photo;
};

InputProfilePhotoStatic Parse(const Value& value, To<InputProfilePhotoStatic>);

}  // namespace tg
