#include <tg/types/chat_member_left.hpp>
#include <tg/types/user.hpp>

#include "common.hpp"

namespace tg {

ChatMemberLeft Parse(const Value& value, To<ChatMemberLeft>) {
    ChatMemberLeft obj{};
    obj.status = ParseComplex<String>(value["status"]);
    obj.user = ParseComplex<User>(value["user"]);
    return obj;
}

}  // namespace tg
