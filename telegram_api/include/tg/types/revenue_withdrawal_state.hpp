#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/revenue_withdrawal_state_failed.hpp>
#include <tg/types/revenue_withdrawal_state_pending.hpp>
#include <tg/types/revenue_withdrawal_state_succeeded.hpp>

namespace tg {

using RevenueWithdrawalState =
    OneOf<RevenueWithdrawalStatePending, RevenueWithdrawalStateSucceeded, RevenueWithdrawalStateFailed>;

RevenueWithdrawalState Parse(const Value& value, To<RevenueWithdrawalState>);

void Serialize(const RevenueWithdrawalState& obj, ValueBuilder& builder);

}  // namespace tg
