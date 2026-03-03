#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct RevenueWithdrawalStateSucceeded {
    String type;
    Integer date;
    String url;
};

RevenueWithdrawalStateSucceeded Parse(const Value& value, To<RevenueWithdrawalStateSucceeded>);

void Serialize(const RevenueWithdrawalStateSucceeded& obj, ValueBuilder& builder);

}  // namespace tg
