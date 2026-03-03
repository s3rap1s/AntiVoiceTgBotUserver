#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct LabeledPrice {
    String label;
    Integer amount;
};

LabeledPrice Parse(const Value& value, To<LabeledPrice>);

void Serialize(const LabeledPrice& obj, ValueBuilder& builder);

}  // namespace tg
