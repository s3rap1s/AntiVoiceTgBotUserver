#pragma once

#include "common.hpp"
#include "transaction_partner_affiliate_program.hpp"
#include "transaction_partner_chat.hpp"
#include "transaction_partner_fragment.hpp"
#include "transaction_partner_other.hpp"
#include "transaction_partner_telegram_ads.hpp"
#include "transaction_partner_telegram_api.hpp"
#include "transaction_partner_user.hpp"

namespace tg {

using TransactionPartner =
    OneOf<TransactionPartnerUser, TransactionPartnerChat,
          TransactionPartnerAffiliateProgram, TransactionPartnerFragment,
          TransactionPartnerTelegramAds, TransactionPartnerTelegramApi,
          TransactionPartnerOther>;

TransactionPartner Parse(const Value& value, To<TransactionPartner>);

}  // namespace tg
