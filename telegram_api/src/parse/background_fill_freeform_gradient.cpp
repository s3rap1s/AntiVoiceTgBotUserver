#include <types/background_fill_freeform_gradient.hpp>

#include "common.hpp"

namespace tg {

BackgroundFillFreeformGradient Parse(const Value& value,
                                     To<BackgroundFillFreeformGradient>) {
    BackgroundFillFreeformGradient obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.color = ParseComplex<Array<Integer>>(value["color"]);
    return obj;
}

}  // namespace tg
