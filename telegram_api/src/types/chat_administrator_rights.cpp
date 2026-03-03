#include <tg/types/chat_administrator_rights.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatAdministratorRights Parse(const Value& value, To<ChatAdministratorRights>) {
    ChatAdministratorRights obj{};
    obj.is_anonymous = ParseComplex<Boolean>(value["is_anonymous"]);
    obj.can_manage_chat = ParseComplex<Boolean>(value["can_manage_chat"]);
    obj.can_delete_messages = ParseComplex<Boolean>(value["can_delete_messages"]);
    obj.can_manage_video_chats = ParseComplex<Boolean>(value["can_manage_video_chats"]);
    obj.can_restrict_members = ParseComplex<Boolean>(value["can_restrict_members"]);
    obj.can_promote_members = ParseComplex<Boolean>(value["can_promote_members"]);
    obj.can_change_info = ParseComplex<Boolean>(value["can_change_info"]);
    obj.can_invite_users = ParseComplex<Boolean>(value["can_invite_users"]);
    obj.can_post_stories = ParseComplex<Boolean>(value["can_post_stories"]);
    obj.can_edit_stories = ParseComplex<Boolean>(value["can_edit_stories"]);
    obj.can_delete_stories = ParseComplex<Boolean>(value["can_delete_stories"]);
    obj.can_post_messages = ParseComplex<Optional<Boolean>>(value["can_post_messages"]);
    obj.can_edit_messages = ParseComplex<Optional<Boolean>>(value["can_edit_messages"]);
    obj.can_pin_messages = ParseComplex<Optional<Boolean>>(value["can_pin_messages"]);
    obj.can_manage_topics = ParseComplex<Optional<Boolean>>(value["can_manage_topics"]);
    obj.can_manage_direct_messages = ParseComplex<Optional<Boolean>>(value["can_manage_direct_messages"]);
    obj.can_manage_tags = ParseComplex<Optional<Boolean>>(value["can_manage_tags"]);
    return obj;
}

void Serialize(const ChatAdministratorRights& obj, ValueBuilder& builder) {
    internal::Put(builder, "is_anonymous", obj.is_anonymous);
    internal::Put(builder, "can_manage_chat", obj.can_manage_chat);
    internal::Put(builder, "can_delete_messages", obj.can_delete_messages);
    internal::Put(builder, "can_manage_video_chats", obj.can_manage_video_chats);
    internal::Put(builder, "can_restrict_members", obj.can_restrict_members);
    internal::Put(builder, "can_promote_members", obj.can_promote_members);
    internal::Put(builder, "can_change_info", obj.can_change_info);
    internal::Put(builder, "can_invite_users", obj.can_invite_users);
    internal::Put(builder, "can_post_stories", obj.can_post_stories);
    internal::Put(builder, "can_edit_stories", obj.can_edit_stories);
    internal::Put(builder, "can_delete_stories", obj.can_delete_stories);
    internal::Put(builder, "can_post_messages", obj.can_post_messages);
    internal::Put(builder, "can_edit_messages", obj.can_edit_messages);
    internal::Put(builder, "can_pin_messages", obj.can_pin_messages);
    internal::Put(builder, "can_manage_topics", obj.can_manage_topics);
    internal::Put(builder, "can_manage_direct_messages", obj.can_manage_direct_messages);
    internal::Put(builder, "can_manage_tags", obj.can_manage_tags);
}

}  // namespace tg
