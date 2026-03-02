#include <types/message.hpp>
#include <types/suggested_post_approval_failed.hpp>
#include <types/suggested_post_price.hpp>

#include "common.hpp"

namespace tg {

SuggestedPostApprovalFailed Parse(const Value& value,
                                  To<SuggestedPostApprovalFailed>) {
    SuggestedPostApprovalFailed obj{};
    obj.suggested_post_message =
        ParseComplex<MessagePtr>(value["suggested_post_message"]);
    obj.price = ParseComplex<SuggestedPostPrice>(value["price"]);
    return obj;
}

}  // namespace tg
