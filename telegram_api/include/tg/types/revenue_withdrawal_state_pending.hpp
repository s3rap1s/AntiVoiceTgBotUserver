#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct RevenueWithdrawalStatePending {
    String type;
};

RevenueWithdrawalStatePending Parse(const Value& value, To<RevenueWithdrawalStatePending>);

void Serialize(const RevenueWithdrawalStatePending& obj, ValueBuilder& builder);

}  // namespace tg
