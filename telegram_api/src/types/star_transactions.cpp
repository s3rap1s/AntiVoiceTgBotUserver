#include <tg/types/star_transaction.hpp>
#include <tg/types/star_transactions.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

StarTransactions Parse(const Value& value, To<StarTransactions>) {
    StarTransactions obj{};
    obj.transactions = ParseComplex<Array<StarTransaction>>(value["transactions"]);
    return obj;
}

void Serialize(const StarTransactions& obj, ValueBuilder& builder) {
    internal::Put(builder, "transactions", obj.transactions);
}

}  // namespace tg
