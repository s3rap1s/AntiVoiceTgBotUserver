#include <tg/types/revenue_withdrawal_state_pending.hpp>

#include "common.hpp"

namespace tg {

RevenueWithdrawalStatePending Parse(const Value& value,
                                    To<RevenueWithdrawalStatePending>) {
    RevenueWithdrawalStatePending obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

}  // namespace tg
