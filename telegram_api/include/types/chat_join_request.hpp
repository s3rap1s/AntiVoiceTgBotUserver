#pragma once

#include <types/chat.hpp>
#include <types/chat_invite_link.hpp>
#include <types/common.hpp>
#include <types/user.hpp>

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

}  // namespace tg
