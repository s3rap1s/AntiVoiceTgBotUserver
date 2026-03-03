#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ChatMemberLeft {
    String status;
    User user;
};

ChatMemberLeft Parse(const Value& value, To<ChatMemberLeft>);

void Serialize(const ChatMemberLeft& obj, ValueBuilder& builder);

}  // namespace tg
