#include <tg/types/mask_position.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

MaskPosition Parse(const Value& value, To<MaskPosition>) {
    MaskPosition obj{};
    obj.point = ParseComplex<String>(value["point"]);
    obj.x_shift = ParseComplex<Float>(value["x_shift"]);
    obj.y_shift = ParseComplex<Float>(value["y_shift"]);
    obj.scale = ParseComplex<Float>(value["scale"]);
    return obj;
}

void Serialize(const MaskPosition& obj, ValueBuilder& builder) {
    internal::Put(builder, "point", obj.point);
    internal::Put(builder, "x_shift", obj.x_shift);
    internal::Put(builder, "y_shift", obj.y_shift);
    internal::Put(builder, "scale", obj.scale);
}

}  // namespace tg
