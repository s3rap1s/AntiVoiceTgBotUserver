#pragma once

#include <types/common.hpp>
#include <types/shipping_address.hpp>

namespace tg {

struct OrderInfo {
    Optional<String> name;
    Optional<String> phone_number;
    Optional<String> email;
    Optional<ShippingAddress> shipping_address;
};

OrderInfo Parse(const Value& value, To<OrderInfo>);

}  // namespace tg
