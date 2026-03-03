#include <tg/types/revenue_withdrawal_state_succeeded.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

RevenueWithdrawalStateSucceeded Parse(const Value& value, To<RevenueWithdrawalStateSucceeded>) {
    RevenueWithdrawalStateSucceeded obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.url = ParseComplex<String>(value["url"]);
    return obj;
}

void Serialize(const RevenueWithdrawalStateSucceeded& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "date", obj.date);
    internal::Put(builder, "url", obj.url);
}

}  // namespace tg
