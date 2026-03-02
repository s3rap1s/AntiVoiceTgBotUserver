#include <types/input_profile_photo_static.hpp>

#include "common.hpp"

namespace tg {

InputProfilePhotoStatic Parse(const Value& value, To<InputProfilePhotoStatic>) {
    InputProfilePhotoStatic obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.photo = ParseComplex<String>(value["photo"]);
    return obj;
}

}  // namespace tg
