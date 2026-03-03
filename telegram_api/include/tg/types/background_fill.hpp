#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/background_fill_freeform_gradient.hpp>
#include <tg/types/background_fill_gradient.hpp>
#include <tg/types/background_fill_solid.hpp>

namespace tg {

using ValueBuilder = userver::formats::json::ValueBuilder;

using BackgroundFill = OneOf<BackgroundFillSolid, BackgroundFillGradient, BackgroundFillFreeformGradient>;

BackgroundFill Parse(const Value& value, To<BackgroundFill>);

void Serialize(const BackgroundFill& obj, ValueBuilder& builder);

}  // namespace tg
