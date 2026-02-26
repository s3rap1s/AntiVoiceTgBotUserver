#pragma once

#include "common.hpp"

namespace tg {

struct RevenueWithdrawalStatePending {
    String type;
};

RevenueWithdrawalStatePending Parse(const Value& value,
                                    To<RevenueWithdrawalStatePending>);

}  // namespace tg
