#include <types/message.hpp>
#include <types/suggested_post_refunded.hpp>

#include "common.hpp"

namespace tg {

SuggestedPostRefunded Parse(const Value& value, To<SuggestedPostRefunded>) {
    SuggestedPostRefunded obj{};
    obj.suggested_post_message =
        ParseComplex<MessagePtr>(value["suggested_post_message"]);
    obj.reason = ParseComplex<String>(value["reason"]);
    return obj;
}

}  // namespace tg
