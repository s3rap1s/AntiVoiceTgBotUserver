#include <tg/types/shipping_address.hpp>
#include <tg/types/shipping_query.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ShippingQuery Parse(const Value& value, To<ShippingQuery>) {
    ShippingQuery obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.from = ParseComplex<User>(value["from"]);
    obj.invoice_payload = ParseComplex<String>(value["invoice_payload"]);
    obj.shipping_address = ParseComplex<ShippingAddress>(value["shipping_address"]);
    return obj;
}

void Serialize(const ShippingQuery& obj, ValueBuilder& builder) {
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "from", obj.from);
    internal::Put(builder, "invoice_payload", obj.invoice_payload);
    internal::Put(builder, "shipping_address", obj.shipping_address);
}

}  // namespace tg
