#pragma once

#include <tg/types/chat.hpp>
#include <tg/types/chat_invite_link.hpp>
#include <tg/types/chat_member.hpp>
#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ChatMemberUpdated {
    Chat chat;
    User user;
    Integer date;
    ChatMember old_chat_member;
    ChatMember new_chat_member;
    Optional<ChatInviteLink> invite_link;
    Optional<Boolean> via_join_request;
    Optional<Boolean> via_chat_folder_invite_link;
};

ChatMemberUpdated Parse(const Value& value, To<ChatMemberUpdated>);

}  // namespace tg
