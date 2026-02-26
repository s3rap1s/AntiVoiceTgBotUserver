#pragma once

#include "common.hpp"

namespace tg {

struct RevenueWithdrawalStateSucceeded {
    String type;
    Integer date;
    String url;
};

RevenueWithdrawalStateSucceeded Parse(const Value& value,
                                      To<RevenueWithdrawalStateSucceeded>);

}  // namespace tg
