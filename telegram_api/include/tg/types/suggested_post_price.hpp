#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct SuggestedPostPrice {
    String currency;
    Integer amount;
};

SuggestedPostPrice Parse(const Value& value, To<SuggestedPostPrice>);

void Serialize(const SuggestedPostPrice& obj, ValueBuilder& builder);

}  // namespace tg
