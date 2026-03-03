#include <tg/types/chat.hpp>
#include <tg/types/chat_invite_link.hpp>
#include <tg/types/chat_member.hpp>
#include <tg/types/chat_member_updated.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatMemberUpdated Parse(const Value& value, To<ChatMemberUpdated>) {
    ChatMemberUpdated obj{};
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.user = ParseComplex<User>(value["user"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.old_chat_member = ParseComplex<ChatMember>(value["old_chat_member"]);
    obj.new_chat_member = ParseComplex<ChatMember>(value["new_chat_member"]);
    obj.invite_link = ParseComplex<Optional<ChatInviteLink>>(value["invite_link"]);
    obj.via_join_request = ParseComplex<Optional<Boolean>>(value["via_join_request"]);
    obj.via_chat_folder_invite_link = ParseComplex<Optional<Boolean>>(value["via_chat_folder_invite_link"]);
    return obj;
}

void Serialize(const ChatMemberUpdated& obj, ValueBuilder& builder) {
    internal::Put(builder, "chat", obj.chat);
    internal::Put(builder, "user", obj.user);
    internal::Put(builder, "date", obj.date);
    internal::Put(builder, "old_chat_member", obj.old_chat_member);
    internal::Put(builder, "new_chat_member", obj.new_chat_member);
    internal::Put(builder, "invite_link", obj.invite_link);
    internal::Put(builder, "via_join_request", obj.via_join_request);
    internal::Put(builder, "via_chat_folder_invite_link", obj.via_chat_folder_invite_link);
}

}  // namespace tg
