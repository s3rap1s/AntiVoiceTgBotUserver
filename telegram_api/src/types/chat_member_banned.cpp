#include <tg/types/chat_member_banned.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatMemberBanned Parse(const Value& value, To<ChatMemberBanned>) {
    ChatMemberBanned obj{};
    obj.status = ParseComplex<String>(value["status"]);
    obj.user = ParseComplex<User>(value["user"]);
    obj.until_date = ParseComplex<Integer>(value["until_date"]);
    return obj;
}

void Serialize(const ChatMemberBanned& obj, ValueBuilder& builder) {
    internal::Put(builder, "status", obj.status);
    internal::Put(builder, "user", obj.user);
    internal::Put(builder, "until_date", obj.until_date);
}

}  // namespace tg
