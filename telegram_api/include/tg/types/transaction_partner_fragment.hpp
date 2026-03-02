#pragma once

#include <tg/types/common.hpp>
#include <tg/types/revenue_withdrawal_state.hpp>

namespace tg {

struct TransactionPartnerFragment {
    String type;
    Optional<RevenueWithdrawalState> withdrawal_state;
};

TransactionPartnerFragment Parse(const Value& value,
                                 To<TransactionPartnerFragment>);

}  // namespace tg
