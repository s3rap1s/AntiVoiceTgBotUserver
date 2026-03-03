#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/star_transaction.hpp>

namespace tg {

struct StarTransactions {
    Array<StarTransaction> transactions;
};

StarTransactions Parse(const Value& value, To<StarTransactions>);

void Serialize(const StarTransactions& obj, ValueBuilder& builder);

}  // namespace tg
