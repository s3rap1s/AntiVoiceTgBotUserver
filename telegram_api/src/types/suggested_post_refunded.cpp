#include <tg/types/message.hpp>
#include <tg/types/suggested_post_refunded.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

SuggestedPostRefunded Parse(const Value& value, To<SuggestedPostRefunded>) {
    SuggestedPostRefunded obj{};
    obj.suggested_post_message = ParseComplex<MessagePtr>(value["suggested_post_message"]);
    obj.reason = ParseComplex<String>(value["reason"]);
    return obj;
}

void Serialize(const SuggestedPostRefunded& obj, ValueBuilder& builder) {
    internal::Put(builder, "suggested_post_message", obj.suggested_post_message);
    internal::Put(builder, "reason", obj.reason);
}

}  // namespace tg
