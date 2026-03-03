#include <tg/types/suggested_post_parameters.hpp>
#include <tg/types/suggested_post_price.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

SuggestedPostParameters Parse(const Value& value, To<SuggestedPostParameters>) {
    SuggestedPostParameters obj{};
    obj.price = ParseComplex<Optional<SuggestedPostPrice>>(value["price"]);
    obj.send_date = ParseComplex<Optional<Integer>>(value["send_date"]);
    return obj;
}

void Serialize(const SuggestedPostParameters& obj, ValueBuilder& builder) {
    internal::Put(builder, "price", obj.price);
    internal::Put(builder, "send_date", obj.send_date);
}

}  // namespace tg
