#pragma once

#include <types/affiliate_info.hpp>
#include <types/common.hpp>
#include <types/gift.hpp>
#include <types/paid_media.hpp>
#include <types/user.hpp>

namespace tg {

struct TransactionPartnerUser {
    String type;
    String transaction_type;
    User user;
    Optional<AffiliateInfo> affiliate;
    Optional<String> invoice_payload;
    Optional<Integer> subscription_period;
    Optional<Array<PaidMedia>> paid_media;
    Optional<String> paid_media_payload;
    Optional<Gift> gift;
    Optional<Integer> premium_subscription_duration;
};

TransactionPartnerUser Parse(const Value& value, To<TransactionPartnerUser>);

}  // namespace tg
