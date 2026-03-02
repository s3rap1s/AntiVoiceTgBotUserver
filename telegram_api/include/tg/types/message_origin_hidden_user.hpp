#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct MessageOriginHiddenUser {
    String type;
    Integer date;
    String sender_user_name;
};

MessageOriginHiddenUser Parse(const Value& value, To<MessageOriginHiddenUser>);

}  // namespace tg
