#pragma once

#include "common.hpp"
#include "user.hpp"

namespace tg {

struct ChatMemberLeft {
    String status;
    User user;
};

ChatMemberLeft Parse(const Value& value, To<ChatMemberLeft>);

}  // namespace tg
