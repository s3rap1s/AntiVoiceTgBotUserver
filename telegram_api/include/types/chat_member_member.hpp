#pragma once

#include <types/common.hpp>
#include <types/user.hpp>

namespace tg {

struct ChatMemberMember {
    String status;
    Optional<String> tag;
    User user;
    Optional<Integer> until_date;
};

ChatMemberMember Parse(const Value& value, To<ChatMemberMember>);

}  // namespace tg
