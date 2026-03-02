#include <types/message.hpp>
#include <types/suggested_post_approved.hpp>
#include <types/suggested_post_price.hpp>

#include "common.hpp"

namespace tg {

SuggestedPostApproved Parse(const Value& value, To<SuggestedPostApproved>) {
    SuggestedPostApproved obj{};
    obj.suggested_post_message =
        ParseComplex<MessagePtr>(value["suggested_post_message"]);
    obj.price = ParseComplex<Optional<SuggestedPostPrice>>(value["price"]);
    obj.send_date = ParseComplex<Integer>(value["send_date"]);
    return obj;
}

}  // namespace tg
