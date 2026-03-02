#include <tg/types/revenue_withdrawal_state_failed.hpp>

#include "common.hpp"

namespace tg {

RevenueWithdrawalStateFailed Parse(const Value& value,
                                   To<RevenueWithdrawalStateFailed>) {
    RevenueWithdrawalStateFailed obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

}  // namespace tg
