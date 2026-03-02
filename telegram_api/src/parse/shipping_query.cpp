#include <tg/types/shipping_address.hpp>
#include <tg/types/shipping_query.hpp>
#include <tg/types/user.hpp>

#include "common.hpp"

namespace tg {

ShippingQuery Parse(const Value& value, To<ShippingQuery>) {
    ShippingQuery obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.from = ParseComplex<User>(value["from"]);
    obj.invoice_payload = ParseComplex<String>(value["invoice_payload"]);
    obj.shipping_address =
        ParseComplex<ShippingAddress>(value["shipping_address"]);
    return obj;
}

}  // namespace tg
