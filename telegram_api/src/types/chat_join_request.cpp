#include <tg/types/chat.hpp>
#include <tg/types/chat_invite_link.hpp>
#include <tg/types/chat_join_request.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatJoinRequest Parse(const Value& value, To<ChatJoinRequest>) {
    ChatJoinRequest obj{};
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.from = ParseComplex<User>(value["from"]);
    obj.user_chat_id = ParseComplex<Integer>(value["user_chat_id"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.bio = ParseComplex<Optional<String>>(value["bio"]);
    obj.invite_link = ParseComplex<Optional<ChatInviteLink>>(value["invite_link"]);
    return obj;
}

void Serialize(const ChatJoinRequest& obj, ValueBuilder& builder) {
    internal::Put(builder, "chat", obj.chat);
    internal::Put(builder, "from", obj.from);
    internal::Put(builder, "user_chat_id", obj.user_chat_id);
    internal::Put(builder, "date", obj.date);
    internal::Put(builder, "bio", obj.bio);
    internal::Put(builder, "invite_link", obj.invite_link);
}

}  // namespace tg
