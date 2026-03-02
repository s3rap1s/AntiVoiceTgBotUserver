#include <tg/types/revenue_withdrawal_state_succeeded.hpp>

#include "common.hpp"

namespace tg {

RevenueWithdrawalStateSucceeded Parse(const Value& value,
                                      To<RevenueWithdrawalStateSucceeded>) {
    RevenueWithdrawalStateSucceeded obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.url = ParseComplex<String>(value["url"]);
    return obj;
}

}  // namespace tg
