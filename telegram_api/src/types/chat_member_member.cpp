#include <tg/types/chat_member_member.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatMemberMember Parse(const Value& value, To<ChatMemberMember>) {
    ChatMemberMember obj{};
    obj.status = ParseComplex<String>(value["status"]);
    obj.tag = ParseComplex<Optional<String>>(value["tag"]);
    obj.user = ParseComplex<User>(value["user"]);
    obj.until_date = ParseComplex<Optional<Integer>>(value["until_date"]);
    return obj;
}

void Serialize(const ChatMemberMember& obj, ValueBuilder& builder) {
    internal::Put(builder, "status", obj.status);
    internal::Put(builder, "tag", obj.tag);
    internal::Put(builder, "user", obj.user);
    internal::Put(builder, "until_date", obj.until_date);
}

}  // namespace tg
