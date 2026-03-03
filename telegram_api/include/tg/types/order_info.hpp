#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/shipping_address.hpp>

namespace tg {

struct OrderInfo {
    Optional<String> name;
    Optional<String> phone_number;
    Optional<String> email;
    Optional<ShippingAddress> shipping_address;
};

OrderInfo Parse(const Value& value, To<OrderInfo>);

void Serialize(const OrderInfo& obj, ValueBuilder& builder);

}  // namespace tg
