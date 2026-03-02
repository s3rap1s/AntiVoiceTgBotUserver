#include <tg/types/chat.hpp>
#include <tg/types/chat_invite_link.hpp>
#include <tg/types/chat_member.hpp>
#include <tg/types/chat_member_updated.hpp>
#include <tg/types/user.hpp>

#include "common.hpp"

namespace tg {

ChatMemberUpdated Parse(const Value& value, To<ChatMemberUpdated>) {
    ChatMemberUpdated obj{};
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.user = ParseComplex<User>(value["user"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.old_chat_member = ParseComplex<ChatMember>(value["old_chat_member"]);
    obj.new_chat_member = ParseComplex<ChatMember>(value["new_chat_member"]);
    obj.invite_link =
        ParseComplex<Optional<ChatInviteLink>>(value["invite_link"]);
    obj.via_join_request =
        ParseComplex<Optional<Boolean>>(value["via_join_request"]);
    obj.via_chat_folder_invite_link =
        ParseComplex<Optional<Boolean>>(value["via_chat_folder_invite_link"]);
    return obj;
}

}  // namespace tg
