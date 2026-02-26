#pragma once

#include "common.hpp"
#include "user.hpp"

namespace tg {

struct ChatMemberBanned {
    String status;
    User user;
    Integer until_date;
};

ChatMemberBanned Parse(const Value& value, To<ChatMemberBanned>);

}  // namespace tg
