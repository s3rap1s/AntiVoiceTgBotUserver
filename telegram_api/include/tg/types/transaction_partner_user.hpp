#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/affiliate_info.hpp>
#include <tg/types/common.hpp>
#include <tg/types/gift.hpp>
#include <tg/types/paid_media.hpp>
#include <tg/types/user.hpp>

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

void Serialize(const TransactionPartnerUser& obj, ValueBuilder& builder);

}  // namespace tg
