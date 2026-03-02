#include <types/revenue_withdrawal_state.hpp>
#include <types/transaction_partner_fragment.hpp>

#include "common.hpp"

namespace tg {

TransactionPartnerFragment Parse(const Value& value,
                                 To<TransactionPartnerFragment>) {
    TransactionPartnerFragment obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.withdrawal_state = ParseComplex<Optional<RevenueWithdrawalState>>(
        value["withdrawal_state"]);
    return obj;
}

}  // namespace tg
