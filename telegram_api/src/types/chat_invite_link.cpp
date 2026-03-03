#include <tg/types/chat_invite_link.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatInviteLink Parse(const Value& value, To<ChatInviteLink>) {
    ChatInviteLink obj{};
    obj.invite_link = ParseComplex<String>(value["invite_link"]);
    obj.creator = ParseComplex<User>(value["creator"]);
    obj.creates_join_request = ParseComplex<Boolean>(value["creates_join_request"]);
    obj.is_primary = ParseComplex<Boolean>(value["is_primary"]);
    obj.is_revoked = ParseComplex<Boolean>(value["is_revoked"]);
    obj.name = ParseComplex<Optional<String>>(value["name"]);
    obj.expire_date = ParseComplex<Optional<Integer>>(value["expire_date"]);
    obj.member_limit = ParseComplex<Optional<Integer>>(value["member_limit"]);
    obj.pending_join_request_count = ParseComplex<Optional<Integer>>(value["pending_join_request_count"]);
    obj.subscription_period = ParseComplex<Optional<Integer>>(value["subscription_period"]);
    obj.subscription_price = ParseComplex<Optional<Integer>>(value["subscription_price"]);
    return obj;
}

void Serialize(const ChatInviteLink& obj, ValueBuilder& builder) {
    internal::Put(builder, "invite_link", obj.invite_link);
    internal::Put(builder, "creator", obj.creator);
    internal::Put(builder, "creates_join_request", obj.creates_join_request);
    internal::Put(builder, "is_primary", obj.is_primary);
    internal::Put(builder, "is_revoked", obj.is_revoked);
    internal::Put(builder, "name", obj.name);
    internal::Put(builder, "expire_date", obj.expire_date);
    internal::Put(builder, "member_limit", obj.member_limit);
    internal::Put(builder, "pending_join_request_count", obj.pending_join_request_count);
    internal::Put(builder, "subscription_period", obj.subscription_period);
    internal::Put(builder, "subscription_price", obj.subscription_price);
}

}  // namespace tg
