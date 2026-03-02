#include <tg/types/chat_member_member.hpp>
#include <tg/types/user.hpp>

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

}  // namespace tg
