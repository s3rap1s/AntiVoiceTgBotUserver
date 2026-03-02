#pragma once

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ChatMemberAdministrator {
    String status;
    User user;
    Boolean can_be_edited;
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
    Optional<Boolean> can_manage_tags;
    Optional<String> custom_title;
};

ChatMemberAdministrator Parse(const Value& value, To<ChatMemberAdministrator>);

}  // namespace tg
