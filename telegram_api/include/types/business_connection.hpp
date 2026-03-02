#pragma once

#include <types/business_bot_rights.hpp>
#include <types/common.hpp>
#include <types/user.hpp>

namespace tg {

struct BusinessConnection {
    String id;
    User user;
    Integer user_chat_id;
    Integer date;
    Optional<BusinessBotRights> rights;
    Boolean is_enabled;
};

BusinessConnection Parse(const Value& value, To<BusinessConnection>);

}  // namespace tg
