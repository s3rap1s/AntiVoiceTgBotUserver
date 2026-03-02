#include <tg/types/order_info.hpp>
#include <tg/types/shipping_address.hpp>

#include "common.hpp"

namespace tg {

OrderInfo Parse(const Value& value, To<OrderInfo>) {
    OrderInfo obj{};
    obj.name = ParseComplex<Optional<String>>(value["name"]);
    obj.phone_number = ParseComplex<Optional<String>>(value["phone_number"]);
    obj.email = ParseComplex<Optional<String>>(value["email"]);
    obj.shipping_address =
        ParseComplex<Optional<ShippingAddress>>(value["shipping_address"]);
    return obj;
}

}  // namespace tg
