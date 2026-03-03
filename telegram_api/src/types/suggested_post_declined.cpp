#include <tg/types/message.hpp>
#include <tg/types/suggested_post_declined.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

SuggestedPostDeclined Parse(const Value& value, To<SuggestedPostDeclined>) {
    SuggestedPostDeclined obj{};
    obj.suggested_post_message = ParseComplex<MessagePtr>(value["suggested_post_message"]);
    obj.comment = ParseComplex<Optional<String>>(value["comment"]);
    return obj;
}

void Serialize(const SuggestedPostDeclined& obj, ValueBuilder& builder) {
    internal::Put(builder, "suggested_post_message", obj.suggested_post_message);
    internal::Put(builder, "comment", obj.comment);
}

}  // namespace tg
