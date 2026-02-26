#pragma once

#include "common.hpp"

namespace tg {

struct InputStoryContentVideo {
    String type;
    String video;
    Optional<Float> duration;
    Optional<Float> main_frame_timestamp;
    Optional<Boolean> is_animation;
};

InputStoryContentVideo Parse(const Value& value, To<InputStoryContentVideo>);

}  // namespace tg
