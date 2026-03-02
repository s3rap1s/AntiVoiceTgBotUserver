#include <tg/types/input_profile_photo_animated.hpp>

#include "common.hpp"

namespace tg {

InputProfilePhotoAnimated Parse(const Value& value,
                                To<InputProfilePhotoAnimated>) {
    InputProfilePhotoAnimated obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.animation = ParseComplex<String>(value["animation"]);
    obj.main_frame_timestamp =
        ParseComplex<Optional<Float>>(value["main_frame_timestamp"]);
    return obj;
}

}  // namespace tg
