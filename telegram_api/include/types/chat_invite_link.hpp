#pragma once

#include <types/common.hpp>
#include <types/user.hpp>

namespace tg {

struct ChatInviteLink {
    String invite_link;
    User creator;
    Boolean creates_join_request;
    Boolean is_primary;
    Boolean is_revoked;
    Optional<String> name;
    Optional<Integer> expire_date;
    Optional<Integer> member_limit;
    Optional<Integer> pending_join_request_count;
    Optional<Integer> subscription_period;
    Optional<Integer> subscription_price;
};

ChatInviteLink Parse(const Value& value, To<ChatInviteLink>);

}  // namespace tg
