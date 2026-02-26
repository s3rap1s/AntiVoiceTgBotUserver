#pragma once

#include "common.hpp"
#include "user.hpp"

namespace tg {

struct ChatOwnerLeft {
    Optional<User> new_owner;
};

ChatOwnerLeft Parse(const Value& value, To<ChatOwnerLeft>);

}  // namespace tg
