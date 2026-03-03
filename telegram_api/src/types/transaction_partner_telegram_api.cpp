#include <tg/types/transaction_partner_telegram_api.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

TransactionPartnerTelegramApi Parse(const Value& value, To<TransactionPartnerTelegramApi>) {
    TransactionPartnerTelegramApi obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.request_count = ParseComplex<Integer>(value["request_count"]);
    return obj;
}

void Serialize(const TransactionPartnerTelegramApi& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "request_count", obj.request_count);
}

}  // namespace tg
