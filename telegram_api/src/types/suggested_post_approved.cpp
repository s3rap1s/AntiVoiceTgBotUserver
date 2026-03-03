#include <tg/types/message.hpp>
#include <tg/types/suggested_post_approved.hpp>
#include <tg/types/suggested_post_price.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

SuggestedPostApproved Parse(const Value& value, To<SuggestedPostApproved>) {
    SuggestedPostApproved obj{};
    obj.suggested_post_message = ParseComplex<MessagePtr>(value["suggested_post_message"]);
    obj.price = ParseComplex<Optional<SuggestedPostPrice>>(value["price"]);
    obj.send_date = ParseComplex<Integer>(value["send_date"]);
    return obj;
}

void Serialize(const SuggestedPostApproved& obj, ValueBuilder& builder) {
    internal::Put(builder, "suggested_post_message", obj.suggested_post_message);
    internal::Put(builder, "price", obj.price);
    internal::Put(builder, "send_date", obj.send_date);
}

}  // namespace tg
