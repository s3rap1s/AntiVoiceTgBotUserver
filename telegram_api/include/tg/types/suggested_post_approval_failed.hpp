#pragma once

#include <tg/types/common.hpp>
#include <tg/types/message_ptr.hpp>
#include <tg/types/suggested_post_price.hpp>

namespace tg {

struct SuggestedPostApprovalFailed {
    MessagePtr suggested_post_message;
    SuggestedPostPrice price;
};

SuggestedPostApprovalFailed Parse(const Value& value,
                                  To<SuggestedPostApprovalFailed>);

}  // namespace tg
