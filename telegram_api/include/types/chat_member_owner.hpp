#pragma once

#include <types/common.hpp>
#include <types/user.hpp>

namespace tg {

struct ChatMemberOwner {
    String status;
    User user;
    Boolean is_anonymous;
    Optional<String> custom_title;
};

ChatMemberOwner Parse(const Value& value, To<ChatMemberOwner>);

}  // namespace tg
