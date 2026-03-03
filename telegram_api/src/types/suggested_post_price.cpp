#include <tg/types/suggested_post_price.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

SuggestedPostPrice Parse(const Value& value, To<SuggestedPostPrice>) {
    SuggestedPostPrice obj{};
    obj.currency = ParseComplex<String>(value["currency"]);
    obj.amount = ParseComplex<Integer>(value["amount"]);
    return obj;
}

void Serialize(const SuggestedPostPrice& obj, ValueBuilder& builder) {
    internal::Put(builder, "currency", obj.currency);
    internal::Put(builder, "amount", obj.amount);
}

}  // namespace tg
