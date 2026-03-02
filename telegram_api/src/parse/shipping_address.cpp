#include <tg/types/shipping_address.hpp>

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

}  // namespace tg
