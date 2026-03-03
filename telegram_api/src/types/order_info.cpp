#include <tg/types/order_info.hpp>
#include <tg/types/shipping_address.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

OrderInfo Parse(const Value& value, To<OrderInfo>) {
    OrderInfo obj{};
    obj.name = ParseComplex<Optional<String>>(value["name"]);
    obj.phone_number = ParseComplex<Optional<String>>(value["phone_number"]);
    obj.email = ParseComplex<Optional<String>>(value["email"]);
    obj.shipping_address = ParseComplex<Optional<ShippingAddress>>(value["shipping_address"]);
    return obj;
}

void Serialize(const OrderInfo& obj, ValueBuilder& builder) {
    internal::Put(builder, "name", obj.name);
    internal::Put(builder, "phone_number", obj.phone_number);
    internal::Put(builder, "email", obj.email);
    internal::Put(builder, "shipping_address", obj.shipping_address);
}

}  // namespace tg
