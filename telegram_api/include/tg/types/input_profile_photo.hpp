#pragma once

#include <tg/types/common.hpp>
#include <tg/types/input_profile_photo_animated.hpp>
#include <tg/types/input_profile_photo_static.hpp>

namespace tg {

using InputProfilePhoto =
    OneOf<InputProfilePhotoStatic, InputProfilePhotoAnimated>;

InputProfilePhoto Parse(const Value& value, To<InputProfilePhoto>);

}  // namespace tg
