#include <tg/types/background_fill.hpp>
#include <tg/types/background_fill_freeform_gradient.hpp>
#include <tg/types/background_fill_gradient.hpp>
#include <tg/types/background_fill_solid.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BackgroundFill Parse(const Value& value, To<BackgroundFill>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "solid") return ParseComplex<BackgroundFillSolid>(value);
    if (type == "gradient") return ParseComplex<BackgroundFillGradient>(value);
    if (type == "freeform_gradient") return ParseComplex<BackgroundFillFreeformGradient>(value);
    throw ParseException("Unknown BackgroundFill type: " + type);
}

void Serialize(const BackgroundFill& obj, ValueBuilder& builder) { internal::Set(builder, obj); }

}  // namespace tg
