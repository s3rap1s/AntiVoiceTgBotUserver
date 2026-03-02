#include <tg/types/message.hpp>
#include <tg/types/star_amount.hpp>
#include <tg/types/suggested_post_paid.hpp>

#include "common.hpp"

namespace tg {

SuggestedPostPaid Parse(const Value& value, To<SuggestedPostPaid>) {
    SuggestedPostPaid obj{};
    obj.suggested_post_message =
        ParseComplex<MessagePtr>(value["suggested_post_message"]);
    obj.currency = ParseComplex<String>(value["currency"]);
    obj.amount = ParseComplex<Optional<Integer>>(value["amount"]);
    obj.star_amount = ParseComplex<Optional<StarAmount>>(value["star_amount"]);
    return obj;
}

}  // namespace tg
