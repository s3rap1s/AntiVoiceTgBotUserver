#pragma once

#include "common.hpp"
#include "suggested_post_price.hpp"

namespace tg {

struct Message;

struct SuggestedPostApprovalFailed {
    Ptr<Message> suggested_post_message;
    SuggestedPostPrice price;
};

SuggestedPostApprovalFailed Parse(const Value& value,
                                  To<SuggestedPostApprovalFailed>);

}  // namespace tg
