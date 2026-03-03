#include <tg/types/chat_member_owner.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatMemberOwner Parse(const Value& value, To<ChatMemberOwner>) {
    ChatMemberOwner obj{};
    obj.status = ParseComplex<String>(value["status"]);
    obj.user = ParseComplex<User>(value["user"]);
    obj.is_anonymous = ParseComplex<Boolean>(value["is_anonymous"]);
    obj.custom_title = ParseComplex<Optional<String>>(value["custom_title"]);
    return obj;
}

void Serialize(const ChatMemberOwner& obj, ValueBuilder& builder) {
    internal::Put(builder, "status", obj.status);
    internal::Put(builder, "user", obj.user);
    internal::Put(builder, "is_anonymous", obj.is_anonymous);
    internal::Put(builder, "custom_title", obj.custom_title);
}

}  // namespace tg
