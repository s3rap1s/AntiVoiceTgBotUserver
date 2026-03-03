#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/transaction_partner_affiliate_program.hpp>
#include <tg/types/transaction_partner_chat.hpp>
#include <tg/types/transaction_partner_fragment.hpp>
#include <tg/types/transaction_partner_other.hpp>
#include <tg/types/transaction_partner_telegram_ads.hpp>
#include <tg/types/transaction_partner_telegram_api.hpp>
#include <tg/types/transaction_partner_user.hpp>

namespace tg {

using TransactionPartner = OneOf<TransactionPartnerUser, TransactionPartnerChat, TransactionPartnerAffiliateProgram,
                                 TransactionPartnerFragment, TransactionPartnerTelegramAds,
                                 TransactionPartnerTelegramApi, TransactionPartnerOther>;

TransactionPartner Parse(const Value& value, To<TransactionPartner>);

void Serialize(const TransactionPartner& obj, ValueBuilder& builder);

}  // namespace tg
