#pragma once

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ChatMemberLeft {
    String status;
    User user;
};

ChatMemberLeft Parse(const Value& value, To<ChatMemberLeft>);

}  // namespace tg
