#include <types/transaction_partner_telegram_ads.hpp>

#include "common.hpp"

namespace tg {

TransactionPartnerTelegramAds Parse(const Value& value,
                                    To<TransactionPartnerTelegramAds>) {
    TransactionPartnerTelegramAds obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

}  // namespace tg
