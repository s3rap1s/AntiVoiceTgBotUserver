#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/transaction_partner.hpp>

namespace tg {

struct StarTransaction {
    String id;
    Integer amount;
    Optional<Integer> nanostar_amount;
    Integer date;
    TransactionPartner partner;
    TransactionPartner receiver;
};

StarTransaction Parse(const Value& value, To<StarTransaction>);
void Serialize(const StarTransaction& obj, ValueBuilder& builder);

}  // namespace tg
