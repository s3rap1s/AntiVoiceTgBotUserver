#pragma once

#include "common.hpp"
#include "revenue_withdrawal_state_failed.hpp"
#include "revenue_withdrawal_state_pending.hpp"
#include "revenue_withdrawal_state_succeeded.hpp"

namespace tg {

using RevenueWithdrawalState =
    OneOf<RevenueWithdrawalStatePending, RevenueWithdrawalStateSucceeded,
          RevenueWithdrawalStateFailed>;

RevenueWithdrawalState Parse(const Value& value, To<RevenueWithdrawalState>);

}  // namespace tg
