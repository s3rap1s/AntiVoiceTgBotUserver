#pragma once

#include <types/common.hpp>
#include <types/message_ptr.hpp>

namespace tg {

struct SuggestedPostDeclined {
    MessagePtr suggested_post_message;
    Optional<String> comment;
};

SuggestedPostDeclined Parse(const Value& value, To<SuggestedPostDeclined>);

}  // namespace tg
