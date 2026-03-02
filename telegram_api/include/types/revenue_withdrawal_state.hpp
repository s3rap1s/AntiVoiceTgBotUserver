#pragma once

#include <types/common.hpp>
#include <types/revenue_withdrawal_state_failed.hpp>
#include <types/revenue_withdrawal_state_pending.hpp>
#include <types/revenue_withdrawal_state_succeeded.hpp>

namespace tg {

using RevenueWithdrawalState =
    OneOf<RevenueWithdrawalStatePending, RevenueWithdrawalStateSucceeded,
          RevenueWithdrawalStateFailed>;

RevenueWithdrawalState Parse(const Value& value, To<RevenueWithdrawalState>);

}  // namespace tg
