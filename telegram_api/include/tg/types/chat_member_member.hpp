#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ChatMemberMember {
    String status;
    Optional<String> tag;
    User user;
    Optional<Integer> until_date;
};

ChatMemberMember Parse(const Value& value, To<ChatMemberMember>);

void Serialize(const ChatMemberMember& obj, ValueBuilder& builder);

}  // namespace tg
