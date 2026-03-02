#include <types/chat_invite_link.hpp>
#include <types/user.hpp>

#include "common.hpp"

namespace tg {

ChatInviteLink Parse(const Value& value, To<ChatInviteLink>) {
    ChatInviteLink obj{};
    obj.invite_link = ParseComplex<String>(value["invite_link"]);
    obj.creator = ParseComplex<User>(value["creator"]);
    obj.creates_join_request =
        ParseComplex<Boolean>(value["creates_join_request"]);
    obj.is_primary = ParseComplex<Boolean>(value["is_primary"]);
    obj.is_revoked = ParseComplex<Boolean>(value["is_revoked"]);
    obj.name = ParseComplex<Optional<String>>(value["name"]);
    obj.expire_date = ParseComplex<Optional<Integer>>(value["expire_date"]);
    obj.member_limit = ParseComplex<Optional<Integer>>(value["member_limit"]);
    obj.pending_join_request_count =
        ParseComplex<Optional<Integer>>(value["pending_join_request_count"]);
    obj.subscription_period =
        ParseComplex<Optional<Integer>>(value["subscription_period"]);
    obj.subscription_price =
        ParseComplex<Optional<Integer>>(value["subscription_price"]);
    return obj;
}

}  // namespace tg
