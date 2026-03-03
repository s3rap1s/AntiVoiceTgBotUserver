#include <tg/types/labeled_price.hpp>
#include <tg/types/shipping_option.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ShippingOption Parse(const Value& value, To<ShippingOption>) {
    ShippingOption obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.title = ParseComplex<String>(value["title"]);
    obj.prices = ParseComplex<Array<LabeledPrice>>(value["prices"]);
    return obj;
}

void Serialize(const ShippingOption& obj, ValueBuilder& builder) {
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "title", obj.title);
    internal::Put(builder, "prices", obj.prices);
}

}  // namespace tg
