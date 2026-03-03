#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/background_fill.hpp>
#include <tg/types/common.hpp>

namespace tg {

struct BackgroundTypeFill {
    String type;
    BackgroundFill fill;
    Integer dark_theme_dimming;
};

BackgroundTypeFill Parse(const Value& value, To<BackgroundTypeFill>);

void Serialize(const BackgroundTypeFill& obj, ValueBuilder& builder);

}  // namespace tg
