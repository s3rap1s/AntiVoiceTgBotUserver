#pragma once

#include "common.hpp"
#include "suggested_post_price.hpp"

namespace tg {

struct Message;

struct SuggestedPostApproved {
    Ptr<Message> suggested_post_message;
    Optional<SuggestedPostPrice> price;
    Integer send_date;
};

SuggestedPostApproved Parse(const Value& value, To<SuggestedPostApproved>);

}  // namespace tg
