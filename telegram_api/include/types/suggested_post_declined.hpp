#pragma once

#include "common.hpp"

namespace tg {

struct Message;

struct SuggestedPostDeclined {
    Ptr<Message> suggested_post_message;
    Optional<String> comment;
};

SuggestedPostDeclined Parse(const Value& value, To<SuggestedPostDeclined>);

}  // namespace tg
