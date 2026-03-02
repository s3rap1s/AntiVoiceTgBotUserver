#pragma once

#include <types/common.hpp>
#include <types/user.hpp>

namespace tg {

struct ChatMemberLeft {
    String status;
    User user;
};

ChatMemberLeft Parse(const Value& value, To<ChatMemberLeft>);

}  // namespace tg
