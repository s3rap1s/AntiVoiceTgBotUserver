#include <types/revenue_withdrawal_state.hpp>
#include <types/revenue_withdrawal_state_failed.hpp>
#include <types/revenue_withdrawal_state_pending.hpp>
#include <types/revenue_withdrawal_state_succeeded.hpp>

#include "common.hpp"

namespace tg {

RevenueWithdrawalState Parse(const Value& value, To<RevenueWithdrawalState>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "pending")
        return ParseComplex<RevenueWithdrawalStatePending>(value);
    if (type == "succeeded")
        return ParseComplex<RevenueWithdrawalStateSucceeded>(value);
    if (type == "failed")
        return ParseComplex<RevenueWithdrawalStateFailed>(value);
    throw std::runtime_error("Unknown RevenueWithdrawalState type: " + type);
}

}  // namespace tg
