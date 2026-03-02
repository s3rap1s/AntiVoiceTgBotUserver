#include <types/labeled_price.hpp>
#include <types/shipping_option.hpp>

#include "common.hpp"

namespace tg {

ShippingOption Parse(const Value& value, To<ShippingOption>) {
    ShippingOption obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.title = ParseComplex<String>(value["title"]);
    obj.prices = ParseComplex<Array<LabeledPrice>>(value["prices"]);
    return obj;
}

}  // namespace tg
