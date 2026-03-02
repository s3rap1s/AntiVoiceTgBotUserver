#include <types/input_profile_photo.hpp>
#include <types/input_profile_photo_animated.hpp>
#include <types/input_profile_photo_static.hpp>

#include "common.hpp"

namespace tg {

InputProfilePhoto Parse(const Value& value, To<InputProfilePhoto>) {
    if (detail::IsPresent(value["photo"]))
        return ParseComplex<InputProfilePhotoStatic>(value);
    if (detail::IsPresent(value["animation"]))
        return ParseComplex<InputProfilePhotoAnimated>(value);
    throw std::runtime_error("Unknown InputProfilePhoto payload");
}

}  // namespace tg
