#pragma once

#include <tg/types/common.hpp>
#include <tg/types/message_ptr.hpp>
#include <tg/types/star_amount.hpp>

namespace tg {

struct SuggestedPostPaid {
    MessagePtr suggested_post_message;
    String currency;
    Optional<Integer> amount;
    Optional<StarAmount> star_amount;
};

SuggestedPostPaid Parse(const Value& value, To<SuggestedPostPaid>);

}  // namespace tg
