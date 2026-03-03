#include <tg/types/input_profile_photo.hpp>
#include <tg/types/input_profile_photo_animated.hpp>
#include <tg/types/input_profile_photo_static.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputProfilePhoto Parse(const Value& value, To<InputProfilePhoto>) {
    if (internal::IsPresent(value["photo"])) return ParseComplex<InputProfilePhotoStatic>(value);
    if (internal::IsPresent(value["animation"])) return ParseComplex<InputProfilePhotoAnimated>(value);
    throw ParseException("Unknown InputProfilePhoto payload");
}

void Serialize(const InputProfilePhoto& obj, ValueBuilder& builder) { internal::Set(builder, obj); }

}  // namespace tg
