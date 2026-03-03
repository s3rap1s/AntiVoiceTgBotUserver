#include <tg/types/background_fill_gradient.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BackgroundFillGradient Parse(const Value& value, To<BackgroundFillGradient>) {
    BackgroundFillGradient obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.top_color = ParseComplex<Integer>(value["top_color"]);
    obj.bottom_color = ParseComplex<Integer>(value["bottom_color"]);
    obj.rotation_angle = ParseComplex<Integer>(value["rotation_angle"]);
    return obj;
}

void Serialize(const BackgroundFillGradient& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "top_color", obj.top_color);
    internal::Put(builder, "bottom_color", obj.bottom_color);
    internal::Put(builder, "rotation_angle", obj.rotation_angle);
}

}  // namespace tg
