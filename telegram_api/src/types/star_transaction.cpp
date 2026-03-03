#include <tg/types/star_transaction.hpp>
#include <tg/types/transaction_partner.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

StarTransaction Parse(const Value& value, To<StarTransaction>) {
    StarTransaction obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.amount = ParseComplex<Integer>(value["amount"]);
    obj.nanostar_amount = ParseComplex<Optional<Integer>>(value["nanostar_amount"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.partner = ParseComplex<TransactionPartner>(value["partner"]);
    obj.receiver = ParseComplex<TransactionPartner>(value["receiver"]);
    return obj;
}

void Serialize(const StarTransaction& obj, ValueBuilder& builder) {
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "amount", obj.amount);
    internal::Put(builder, "nanostar_amount", obj.nanostar_amount);
    internal::Put(builder, "date", obj.date);
    internal::Put(builder, "partner", obj.partner);
    internal::Put(builder, "receiver", obj.receiver);
}

}  // namespace tg
