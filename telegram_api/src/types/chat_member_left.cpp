#include <tg/types/chat_member_left.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatMemberLeft Parse(const Value& value, To<ChatMemberLeft>) {
    ChatMemberLeft obj{};
    obj.status = ParseComplex<String>(value["status"]);
    obj.user = ParseComplex<User>(value["user"]);
    return obj;
}

void Serialize(const ChatMemberLeft& obj, ValueBuilder& builder) {
    internal::Put(builder, "status", obj.status);
    internal::Put(builder, "user", obj.user);
}

}  // namespace tg
