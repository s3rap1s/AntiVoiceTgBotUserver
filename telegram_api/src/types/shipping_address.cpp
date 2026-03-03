#include <tg/types/shipping_address.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ShippingAddress Parse(const Value& value, To<ShippingAddress>) {
    ShippingAddress obj{};
    obj.country_code = ParseComplex<String>(value["country_code"]);
    obj.state = ParseComplex<String>(value["state"]);
    obj.city = ParseComplex<String>(value["city"]);
    obj.street_line1 = ParseComplex<String>(value["street_line1"]);
    obj.street_line2 = ParseComplex<String>(value["street_line2"]);
    obj.post_code = ParseComplex<String>(value["post_code"]);
    return obj;
}

void Serialize(const ShippingAddress& obj, ValueBuilder& builder) {
    internal::Put(builder, "country_code", obj.country_code);
    internal::Put(builder, "state", obj.state);
    internal::Put(builder, "city", obj.city);
    internal::Put(builder, "street_line1", obj.street_line1);
    internal::Put(builder, "street_line2", obj.street_line2);
    internal::Put(builder, "post_code", obj.post_code);
}

}  // namespace tg
