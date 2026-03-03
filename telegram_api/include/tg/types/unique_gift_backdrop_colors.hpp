#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct UniqueGiftBackdropColors {
    Integer center_color;
    Integer edge_color;
    Integer symbol_color;
    Integer text_color;
};

UniqueGiftBackdropColors Parse(const Value& value, To<UniqueGiftBackdropColors>);

void Serialize(const UniqueGiftBackdropColors& obj, ValueBuilder& builder);

}  // namespace tg
