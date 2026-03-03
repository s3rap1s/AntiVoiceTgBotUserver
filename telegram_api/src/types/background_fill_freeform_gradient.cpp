#include <tg/types/background_fill_freeform_gradient.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BackgroundFillFreeformGradient Parse(const Value& value, To<BackgroundFillFreeformGradient>) {
    BackgroundFillFreeformGradient obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.color = ParseComplex<Array<Integer>>(value["color"]);
    return obj;
}

void Serialize(const BackgroundFillFreeformGradient& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "color", obj.color);
}

}  // namespace tg
