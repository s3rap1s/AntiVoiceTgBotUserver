#pragma once

#include "common.hpp"
#include "input_profile_photo_animated.hpp"
#include "input_profile_photo_static.hpp"

namespace tg {

using InputProfilePhoto =
    OneOf<InputProfilePhotoStatic, InputProfilePhotoAnimated>;

InputProfilePhoto Parse(const Value& value, To<InputProfilePhoto>);

}  // namespace tg
