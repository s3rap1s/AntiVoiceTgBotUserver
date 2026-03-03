#include <tg/types/message.hpp>
#include <tg/types/star_amount.hpp>
#include <tg/types/suggested_post_paid.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

SuggestedPostPaid Parse(const Value& value, To<SuggestedPostPaid>) {
    SuggestedPostPaid obj{};
    obj.suggested_post_message = ParseComplex<MessagePtr>(value["suggested_post_message"]);
    obj.currency = ParseComplex<String>(value["currency"]);
    obj.amount = ParseComplex<Optional<Integer>>(value["amount"]);
    obj.star_amount = ParseComplex<Optional<StarAmount>>(value["star_amount"]);
    return obj;
}

void Serialize(const SuggestedPostPaid& obj, ValueBuilder& builder) {
    internal::Put(builder, "suggested_post_message", obj.suggested_post_message);
    internal::Put(builder, "currency", obj.currency);
    internal::Put(builder, "amount", obj.amount);
    internal::Put(builder, "star_amount", obj.star_amount);
}

}  // namespace tg
