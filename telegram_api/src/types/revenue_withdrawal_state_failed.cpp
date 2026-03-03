#include <tg/types/revenue_withdrawal_state_failed.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

RevenueWithdrawalStateFailed Parse(const Value& value, To<RevenueWithdrawalStateFailed>) {
    RevenueWithdrawalStateFailed obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

void Serialize(const RevenueWithdrawalStateFailed& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
}

}  // namespace tg
