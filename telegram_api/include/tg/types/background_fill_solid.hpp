#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct BackgroundFillSolid {
    String type;
    Integer color;
};

BackgroundFillSolid Parse(const Value& value, To<BackgroundFillSolid>);

void Serialize(const BackgroundFillSolid& obj, ValueBuilder& builder);

}  // namespace tg
