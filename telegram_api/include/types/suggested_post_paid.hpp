#pragma once

#include "common.hpp"
#include "message.hpp"
#include "star_amount.hpp"

namespace tg {

struct SuggestedPostPaid {
    Ptr<Message> suggested_post_message;
    String currency;
    Optional<Integer> amount;
    Optional<StarAmount> star_amount;
};

SuggestedPostPaid Parse(const Value& value, To<SuggestedPostPaid>);

}  // namespace tg
