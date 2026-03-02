#pragma once

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ChatMemberBanned {
    String status;
    User user;
    Integer until_date;
};

ChatMemberBanned Parse(const Value& value, To<ChatMemberBanned>);

}  // namespace tg
