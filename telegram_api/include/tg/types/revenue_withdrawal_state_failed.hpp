#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct RevenueWithdrawalStateFailed {
    String type;
};

RevenueWithdrawalStateFailed Parse(const Value& value, To<RevenueWithdrawalStateFailed>);

void Serialize(const RevenueWithdrawalStateFailed& obj, ValueBuilder& builder);

}  // namespace tg
