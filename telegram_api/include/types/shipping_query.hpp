#pragma once

#include "common.hpp"
#include "shipping_address.hpp"
#include "user.hpp"

namespace tg {

struct ShippingQuery {
    String id;
    User from;
    String invoice_payload;
    ShippingAddress shipping_address;
};

ShippingQuery Parse(const Value& value, To<ShippingQuery>);

}  // namespace tg
