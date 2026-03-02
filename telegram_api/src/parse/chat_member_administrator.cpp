#include <types/chat_member_administrator.hpp>
#include <types/user.hpp>

#include "common.hpp"

namespace tg {

ChatMemberAdministrator Parse(const Value& value, To<ChatMemberAdministrator>) {
    ChatMemberAdministrator obj{};
    obj.status = ParseComplex<String>(value["status"]);
    obj.user = ParseComplex<User>(value["user"]);
    obj.can_be_edited = ParseComplex<Boolean>(value["can_be_edited"]);
    obj.is_anonymous = ParseComplex<Boolean>(value["is_anonymous"]);
    obj.can_manage_chat = ParseComplex<Boolean>(value["can_manage_chat"]);
    obj.can_delete_messages =
        ParseComplex<Boolean>(value["can_delete_messages"]);
    obj.can_manage_video_chats =
        ParseComplex<Boolean>(value["can_manage_video_chats"]);
    obj.can_restrict_members =
        ParseComplex<Boolean>(value["can_restrict_members"]);
    obj.can_promote_members =
        ParseComplex<Boolean>(value["can_promote_members"]);
    obj.can_change_info = ParseComplex<Boolean>(value["can_change_info"]);
    obj.can_invite_users = ParseComplex<Boolean>(value["can_invite_users"]);
    obj.can_post_stories = ParseComplex<Boolean>(value["can_post_stories"]);
    obj.can_edit_stories = ParseComplex<Boolean>(value["can_edit_stories"]);
    obj.can_delete_stories = ParseComplex<Boolean>(value["can_delete_stories"]);
    obj.can_post_messages =
        ParseComplex<Optional<Boolean>>(value["can_post_messages"]);
    obj.can_edit_messages =
        ParseComplex<Optional<Boolean>>(value["can_edit_messages"]);
    obj.can_pin_messages =
        ParseComplex<Optional<Boolean>>(value["can_pin_messages"]);
    obj.can_manage_topics =
        ParseComplex<Optional<Boolean>>(value["can_manage_topics"]);
    obj.can_manage_direct_messages =
        ParseComplex<Optional<Boolean>>(value["can_manage_direct_messages"]);
    obj.can_manage_tags =
        ParseComplex<Optional<Boolean>>(value["can_manage_tags"]);
    obj.custom_title = ParseComplex<Optional<String>>(value["custom_title"]);
    return obj;
}

}  // namespace tg
