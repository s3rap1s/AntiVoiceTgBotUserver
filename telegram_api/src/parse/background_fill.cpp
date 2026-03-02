#include <types/background_fill.hpp>
#include <types/background_fill_freeform_gradient.hpp>
#include <types/background_fill_gradient.hpp>
#include <types/background_fill_solid.hpp>

#include "common.hpp"

namespace tg {

BackgroundFill Parse(const Value& value, To<BackgroundFill>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "solid") return ParseComplex<BackgroundFillSolid>(value);
    if (type == "gradient") return ParseComplex<BackgroundFillGradient>(value);
    if (type == "freeform_gradient")
        return ParseComplex<BackgroundFillFreeformGradient>(value);
    throw std::runtime_error("Unknown BackgroundFill type: " + type);
}

}  // namespace tg
