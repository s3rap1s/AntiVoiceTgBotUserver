#pragma once

#include <types/common.hpp>
#include <types/user.hpp>

namespace tg {

struct ChatOwnerChanged {
    Optional<User> new_owner;
};

ChatOwnerChanged Parse(const Value& value, To<ChatOwnerChanged>);

}  // namespace tg
