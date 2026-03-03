#include <tg/types/transaction_partner_telegram_ads.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

TransactionPartnerTelegramAds Parse(const Value& value, To<TransactionPartnerTelegramAds>) {
    TransactionPartnerTelegramAds obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

void Serialize(const TransactionPartnerTelegramAds& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
}

}  // namespace tg
