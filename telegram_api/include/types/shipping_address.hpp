#pragma once

#include <types/common.hpp>

namespace tg {

struct ShippingAddress {
    String country_code;
    String state;
    String city;
    String street_line1;
    String street_line2;
    String post_code;
};

ShippingAddress Parse(const Value& value, To<ShippingAddress>);

}  // namespace tg
