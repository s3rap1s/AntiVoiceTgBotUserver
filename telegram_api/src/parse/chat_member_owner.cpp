#include <tg/types/chat_member_owner.hpp>
#include <tg/types/user.hpp>

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

}  // namespace tg
