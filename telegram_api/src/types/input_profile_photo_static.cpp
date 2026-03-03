#include <tg/types/input_profile_photo_static.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputProfilePhotoStatic Parse(const Value& value, To<InputProfilePhotoStatic>) {
    InputProfilePhotoStatic obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.photo = ParseComplex<String>(value["photo"]);
    return obj;
}

void Serialize(const InputProfilePhotoStatic& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "photo", obj.photo);
}

}  // namespace tg
