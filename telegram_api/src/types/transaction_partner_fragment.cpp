#include <tg/types/revenue_withdrawal_state.hpp>
#include <tg/types/transaction_partner_fragment.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

TransactionPartnerFragment Parse(const Value& value, To<TransactionPartnerFragment>) {
    TransactionPartnerFragment obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.withdrawal_state = ParseComplex<Optional<RevenueWithdrawalState>>(value["withdrawal_state"]);
    return obj;
}

void Serialize(const TransactionPartnerFragment& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "withdrawal_state", obj.withdrawal_state);
}

}  // namespace tg
