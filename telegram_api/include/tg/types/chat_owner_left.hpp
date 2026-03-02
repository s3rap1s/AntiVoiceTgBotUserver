#pragma once

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ChatOwnerLeft {
    Optional<User> new_owner;
};

ChatOwnerLeft Parse(const Value& value, To<ChatOwnerLeft>);

}  // namespace tg
