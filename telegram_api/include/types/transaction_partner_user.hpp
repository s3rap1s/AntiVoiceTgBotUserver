#pragma once

#include "affiliate_info.hpp"
#include "common.hpp"
#include "gift.hpp"
#include "paid_media.hpp"
#include "user.hpp"

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
