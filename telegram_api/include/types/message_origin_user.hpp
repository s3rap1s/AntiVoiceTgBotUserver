#pragma once

#include "common.hpp"
#include "user.hpp"

namespace tg {

struct MessageOriginUser {
    String type;
    Integer date;
    User sender_user;
};

MessageOriginUser Parse(const Value& value, To<MessageOriginUser>);

}  // namespace tg
