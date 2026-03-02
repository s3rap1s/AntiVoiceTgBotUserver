#pragma once

#include <types/chat.hpp>
#include <types/common.hpp>
#include <types/user.hpp>

namespace tg {

struct AffiliateInfo {
    User affiliate_user;
    Chat affiliate_chat;
    Integer commission_per_mille;
    Integer amount;
    Optional<Integer> nanostar_amount;
};

AffiliateInfo Parse(const Value& value, To<AffiliateInfo>);

}  // namespace tg
