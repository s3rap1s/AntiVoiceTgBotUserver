#include <types/star_transaction.hpp>
#include <types/transaction_partner.hpp>

#include "common.hpp"

namespace tg {

StarTransaction Parse(const Value& value, To<StarTransaction>) {
    StarTransaction obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.amount = ParseComplex<Integer>(value["amount"]);
    obj.nanostar_amount =
        ParseComplex<Optional<Integer>>(value["nanostar_amount"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.partner = ParseComplex<TransactionPartner>(value["partner"]);
    obj.receiver = ParseComplex<TransactionPartner>(value["receiver"]);
    return obj;
}

}  // namespace tg
