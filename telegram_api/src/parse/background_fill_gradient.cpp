#include <tg/types/background_fill_gradient.hpp>

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

}  // namespace tg
