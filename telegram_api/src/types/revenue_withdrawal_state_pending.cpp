#include <tg/types/revenue_withdrawal_state_pending.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

RevenueWithdrawalStatePending Parse(const Value& value, To<RevenueWithdrawalStatePending>) {
    RevenueWithdrawalStatePending obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

void Serialize(const RevenueWithdrawalStatePending& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
}

}  // namespace tg
