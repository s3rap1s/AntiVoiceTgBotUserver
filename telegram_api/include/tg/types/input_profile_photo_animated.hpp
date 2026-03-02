#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct InputProfilePhotoAnimated {
    String type;
    String animation;
    Optional<Float> main_frame_timestamp;
};

InputProfilePhotoAnimated Parse(const Value& value,
                                To<InputProfilePhotoAnimated>);

}  // namespace tg
