#pragma once

#include <types/common.hpp>
#include <types/message_ptr.hpp>
#include <types/suggested_post_price.hpp>

namespace tg {

struct SuggestedPostApproved {
    MessagePtr suggested_post_message;
    Optional<SuggestedPostPrice> price;
    Integer send_date;
};

SuggestedPostApproved Parse(const Value& value, To<SuggestedPostApproved>);

}  // namespace tg
