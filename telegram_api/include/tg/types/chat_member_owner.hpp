#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ChatMemberOwner {
    String status;
    User user;
    Boolean is_anonymous;
    Optional<String> custom_title;
};

ChatMemberOwner Parse(const Value& value, To<ChatMemberOwner>);

void Serialize(const ChatMemberOwner& obj, ValueBuilder& builder);

}  // namespace tg
