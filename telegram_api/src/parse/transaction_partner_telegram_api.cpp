#include <tg/types/transaction_partner_telegram_api.hpp>

#include "common.hpp"

namespace tg {

TransactionPartnerTelegramApi Parse(const Value& value,
                                    To<TransactionPartnerTelegramApi>) {
    TransactionPartnerTelegramApi obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.request_count = ParseComplex<Integer>(value["request_count"]);
    return obj;
}

}  // namespace tg
