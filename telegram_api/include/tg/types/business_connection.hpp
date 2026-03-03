#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/business_bot_rights.hpp>
#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

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

void Serialize(const BusinessConnection& obj, ValueBuilder& builder);

}  // namespace tg
