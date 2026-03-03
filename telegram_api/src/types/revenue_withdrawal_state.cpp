#include <tg/types/revenue_withdrawal_state.hpp>
#include <tg/types/revenue_withdrawal_state_failed.hpp>
#include <tg/types/revenue_withdrawal_state_pending.hpp>
#include <tg/types/revenue_withdrawal_state_succeeded.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

RevenueWithdrawalState Parse(const Value& value, To<RevenueWithdrawalState>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "pending") return ParseComplex<RevenueWithdrawalStatePending>(value);
    if (type == "succeeded") return ParseComplex<RevenueWithdrawalStateSucceeded>(value);
    if (type == "failed") return ParseComplex<RevenueWithdrawalStateFailed>(value);
    throw ParseException("Unknown RevenueWithdrawalState type: " + type);
}

void Serialize(const RevenueWithdrawalState& obj, ValueBuilder& builder) { internal::Set(builder, obj); }

}  // namespace tg
