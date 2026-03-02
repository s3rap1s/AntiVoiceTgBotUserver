#include <types/chat.hpp>
#include <types/chat_invite_link.hpp>
#include <types/chat_join_request.hpp>
#include <types/user.hpp>

#include "common.hpp"

namespace tg {

ChatJoinRequest Parse(const Value& value, To<ChatJoinRequest>) {
    ChatJoinRequest obj{};
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.from = ParseComplex<User>(value["from"]);
    obj.user_chat_id = ParseComplex<Integer>(value["user_chat_id"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.bio = ParseComplex<Optional<String>>(value["bio"]);
    obj.invite_link =
        ParseComplex<Optional<ChatInviteLink>>(value["invite_link"]);
    return obj;
}

}  // namespace tg
