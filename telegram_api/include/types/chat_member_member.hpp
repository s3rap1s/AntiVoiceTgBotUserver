#pragma once

#include "common.hpp"
#include "user.hpp"

namespace tg {

struct ChatMemberMember {
    String status;
    User user;
    Optional<Integer> until_date;
};

ChatMemberMember Parse(const Value& value, To<ChatMemberMember>);

}  // namespace tg
