#pragma once

#include <userver/formats/json/value_builder.hpp>

#include "chat_member_administrator.hpp"
#include "chat_member_banned.hpp"
#include "chat_member_left.hpp"
#include "chat_member_member.hpp"
#include "chat_member_owner.hpp"
#include "chat_member_restricted.hpp"

namespace tg {

using ValueBuilder = userver::formats::json::ValueBuilder;

using ChatMember = OneOf<ChatMemberOwner, ChatMemberAdministrator, ChatMemberMember, ChatMemberRestricted,
                         ChatMemberLeft, ChatMemberBanned>;

ChatMember Parse(const Value& value, To<ChatMember>);

void Serialize(const ChatMember& obj, ValueBuilder& builder);

}  // namespace tg
