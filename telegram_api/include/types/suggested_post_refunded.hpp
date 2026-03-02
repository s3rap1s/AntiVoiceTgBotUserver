#pragma once

#include <types/common.hpp>
#include <types/message_ptr.hpp>

namespace tg {

struct SuggestedPostRefunded {
    MessagePtr suggested_post_message;
    String reason;
};

SuggestedPostRefunded Parse(const Value& value, To<SuggestedPostRefunded>);

}  // namespace tg
