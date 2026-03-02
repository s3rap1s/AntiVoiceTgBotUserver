#pragma once

#include <tg/types/common.hpp>
#include <tg/types/message_ptr.hpp>

namespace tg {

struct SuggestedPostRefunded {
    MessagePtr suggested_post_message;
    String reason;
};

SuggestedPostRefunded Parse(const Value& value, To<SuggestedPostRefunded>);

}  // namespace tg
