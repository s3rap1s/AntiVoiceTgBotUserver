#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/shipping_address.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ShippingQuery {
    String id;
    User from;
    String invoice_payload;
    ShippingAddress shipping_address;
};

ShippingQuery Parse(const Value& value, To<ShippingQuery>);

void Serialize(const ShippingQuery& obj, ValueBuilder& builder);

}  // namespace tg
