#include <types/message.hpp>
#include <types/suggested_post_declined.hpp>

#include "common.hpp"

namespace tg {

SuggestedPostDeclined Parse(const Value& value, To<SuggestedPostDeclined>) {
    SuggestedPostDeclined obj{};
    obj.suggested_post_message =
        ParseComplex<MessagePtr>(value["suggested_post_message"]);
    obj.comment = ParseComplex<Optional<String>>(value["comment"]);
    return obj;
}

}  // namespace tg
