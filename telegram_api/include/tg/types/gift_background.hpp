#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct GiftBackground {
    Integer center_color;
    Integer edge_color;
    Integer text_color;
};

GiftBackground Parse(const Value& value, To<GiftBackground>);

void Serialize(const GiftBackground& obj, ValueBuilder& builder);

}  // namespace tg
