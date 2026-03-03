#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include "labeled_price.hpp"

namespace tg {

struct ShippingOption {
    String id;
    String title;
    Array<LabeledPrice> prices;
};

ShippingOption Parse(const Value& value, To<ShippingOption>);

void Serialize(const ShippingOption& obj, ValueBuilder& builder);

}  // namespace tg
