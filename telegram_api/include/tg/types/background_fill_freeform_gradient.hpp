#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct BackgroundFillFreeformGradient {
    String type;
    Array<Integer> color;
};

BackgroundFillFreeformGradient Parse(const Value& value, To<BackgroundFillFreeformGradient>);

void Serialize(const BackgroundFillFreeformGradient& obj, ValueBuilder& builder);

}  // namespace tg
