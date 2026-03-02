#include <tg/types/chat_member_banned.hpp>
#include <tg/types/user.hpp>

#include "common.hpp"

namespace tg {

ChatMemberBanned Parse(const Value& value, To<ChatMemberBanned>) {
    ChatMemberBanned obj{};
    obj.status = ParseComplex<String>(value["status"]);
    obj.user = ParseComplex<User>(value["user"]);
    obj.until_date = ParseComplex<Integer>(value["until_date"]);
    return obj;
}

}  // namespace tg
