#pragma once

#include <types/common.hpp>

namespace tg {

struct RevenueWithdrawalStateFailed {
    String type;
};

RevenueWithdrawalStateFailed Parse(const Value& value,
                                   To<RevenueWithdrawalStateFailed>);

}  // namespace tg
