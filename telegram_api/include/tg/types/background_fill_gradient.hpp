#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct BackgroundFillGradient {
    String type;
    Integer top_color;
    Integer bottom_color;
    Integer rotation_angle;
};

BackgroundFillGradient Parse(const Value& value, To<BackgroundFillGradient>);

void Serialize(const BackgroundFillGradient& obj, ValueBuilder& builder);

}  // namespace tg
