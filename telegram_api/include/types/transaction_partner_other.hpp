#pragma once

#include <types/common.hpp>

namespace tg {

struct TransactionPartnerOther {
    String type;
};

TransactionPartnerOther Parse(const Value& value, To<TransactionPartnerOther>);

}  // namespace tg
