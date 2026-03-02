#include <types/suggested_post_price.hpp>

#include "common.hpp"

namespace tg {

SuggestedPostPrice Parse(const Value& value, To<SuggestedPostPrice>) {
    SuggestedPostPrice obj{};
    obj.currency = ParseComplex<String>(value["currency"]);
    obj.amount = ParseComplex<Integer>(value["amount"]);
    return obj;
}

}  // namespace tg
