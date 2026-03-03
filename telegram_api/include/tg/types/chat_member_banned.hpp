#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ChatMemberBanned {
    String status;
    User user;
    Integer until_date;
};

ChatMemberBanned Parse(const Value& value, To<ChatMemberBanned>);

void Serialize(const ChatMemberBanned& obj, ValueBuilder& builder);

}  // namespace tg
