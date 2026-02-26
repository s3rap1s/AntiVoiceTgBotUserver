#pragma once

#include "common.hpp"

namespace tg {

struct Message;

struct SuggestedPostRefunded {
    Ptr<Message> suggested_post_message;
    String reason;
};

SuggestedPostRefunded Parse(const Value& value, To<SuggestedPostRefunded>);

}  // namespace tg
