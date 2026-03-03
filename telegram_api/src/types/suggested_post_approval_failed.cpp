#include <tg/types/message.hpp>
#include <tg/types/suggested_post_approval_failed.hpp>
#include <tg/types/suggested_post_price.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

SuggestedPostApprovalFailed Parse(const Value& value, To<SuggestedPostApprovalFailed>) {
    SuggestedPostApprovalFailed obj{};
    obj.suggested_post_message = ParseComplex<MessagePtr>(value["suggested_post_message"]);
    obj.price = ParseComplex<SuggestedPostPrice>(value["price"]);
    return obj;
}

void Serialize(const SuggestedPostApprovalFailed& obj, ValueBuilder& builder) {
    internal::Put(builder, "suggested_post_message", obj.suggested_post_message);
    internal::Put(builder, "price", obj.price);
}

}  // namespace tg
