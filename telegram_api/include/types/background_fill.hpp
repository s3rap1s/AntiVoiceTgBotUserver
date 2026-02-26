#pragma once

#include "background_fill_freeform_gradient.hpp"
#include "background_fill_gradient.hpp"
#include "background_fill_solid.hpp"

namespace tg {

using BackgroundFill = OneOf<BackgroundFillSolid, BackgroundFillGradient,
                             BackgroundFillFreeformGradient>;

BackgroundFill Parse(const Value& value, To<BackgroundFill>);

}  // namespace tg
