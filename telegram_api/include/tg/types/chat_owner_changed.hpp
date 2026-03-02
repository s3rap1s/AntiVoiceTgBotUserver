#pragma once

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ChatOwnerChanged {
    Optional<User> new_owner;
};

ChatOwnerChanged Parse(const Value& value, To<ChatOwnerChanged>);

}  // namespace tg
