#include <types/mask_position.hpp>

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

}  // namespace tg
