#pragma once

#include <tg/types/common.hpp>
#include <tg/types/star_transaction.hpp>

namespace tg {

struct StarTransactions {
    Array<StarTransaction> transactions;
};

StarTransactions Parse(const Value& value, To<StarTransactions>);

}  // namespace tg
