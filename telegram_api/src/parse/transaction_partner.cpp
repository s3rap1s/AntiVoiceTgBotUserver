#include <tg/types/transaction_partner.hpp>
#include <tg/types/transaction_partner_affiliate_program.hpp>
#include <tg/types/transaction_partner_chat.hpp>
#include <tg/types/transaction_partner_fragment.hpp>
#include <tg/types/transaction_partner_other.hpp>
#include <tg/types/transaction_partner_telegram_ads.hpp>
#include <tg/types/transaction_partner_telegram_api.hpp>
#include <tg/types/transaction_partner_user.hpp>

#include "common.hpp"

namespace tg {

TransactionPartner Parse(const Value& value, To<TransactionPartner>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "user") return ParseComplex<TransactionPartnerUser>(value);
    if (type == "chat") return ParseComplex<TransactionPartnerChat>(value);
    if (type == "affiliate_program")
        return ParseComplex<TransactionPartnerAffiliateProgram>(value);
    if (type == "fragment")
        return ParseComplex<TransactionPartnerFragment>(value);
    if (type == "telegram_ads")
        return ParseComplex<TransactionPartnerTelegramAds>(value);
    if (type == "telegram_api")
        return ParseComplex<TransactionPartnerTelegramApi>(value);
    if (type == "other") return ParseComplex<TransactionPartnerOther>(value);
    throw std::runtime_error("Unknown TransactionPartner type: " + type);
}

}  // namespace tg
