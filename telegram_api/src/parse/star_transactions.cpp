#include <tg/types/star_transaction.hpp>
#include <tg/types/star_transactions.hpp>

#include "common.hpp"

namespace tg {

StarTransactions Parse(const Value& value, To<StarTransactions>) {
    StarTransactions obj{};
    obj.transactions =
        ParseComplex<Array<StarTransaction>>(value["transactions"]);
    return obj;
}

}  // namespace tg
