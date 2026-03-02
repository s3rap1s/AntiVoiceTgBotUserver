#pragma once

#include <types/common.hpp>
#include <types/transaction_partner_affiliate_program.hpp>
#include <types/transaction_partner_chat.hpp>
#include <types/transaction_partner_fragment.hpp>
#include <types/transaction_partner_other.hpp>
#include <types/transaction_partner_telegram_ads.hpp>
#include <types/transaction_partner_telegram_api.hpp>
#include <types/transaction_partner_user.hpp>

namespace tg {

using TransactionPartner =
    OneOf<TransactionPartnerUser, TransactionPartnerChat,
          TransactionPartnerAffiliateProgram, TransactionPartnerFragment,
          TransactionPartnerTelegramAds, TransactionPartnerTelegramApi,
          TransactionPartnerOther>;

TransactionPartner Parse(const Value& value, To<TransactionPartner>);

}  // namespace tg
