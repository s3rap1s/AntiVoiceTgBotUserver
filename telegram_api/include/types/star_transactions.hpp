#pragma once

#include "common.hpp"
#include "star_transaction.hpp"

namespace tg {

struct StarTransactions {
    Array<StarTransaction> transactions;
};

StarTransactions Parse(const Value& value, To<StarTransactions>);

}  // namespace tg
