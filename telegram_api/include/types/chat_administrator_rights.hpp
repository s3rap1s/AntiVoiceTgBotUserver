#pragma once

#include "common.hpp"

namespace tg {

struct ChatAdministratorRights {
    Boolean is_anonymous;
    Boolean can_manage_chat;
    Boolean can_delete_messages;
    Boolean can_manage_video_chats;
    Boolean can_restrict_members;
    Boolean can_promote_members;
    Boolean can_change_info;
    Boolean can_invite_users;
    Boolean can_post_stories;
    Boolean can_edit_stories;
    Boolean can_delete_stories;
    Optional<Boolean> can_post_messages;
    Optional<Boolean> can_edit_messages;
    Optional<Boolean> can_pin_messages;
    Optional<Boolean> can_manage_topics;
    Optional<Boolean> can_manage_direct_messages;
};

ChatAdministratorRights Parse(const Value& value, To<ChatAdministratorRights>);

}  // namespace tg
