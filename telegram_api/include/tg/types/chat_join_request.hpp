#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/chat.hpp>
#include <tg/types/chat_invite_link.hpp>
#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ChatJoinRequest {
    Chat chat;
    User from;
    Integer user_chat_id;
    Integer date;
    Optional<String> bio;
    Optional<ChatInviteLink> invite_link;
};

ChatJoinRequest Parse(const Value& value, To<ChatJoinRequest>);

void Serialize(const ChatJoinRequest& obj, ValueBuilder& builder);

}  // namespace tg
