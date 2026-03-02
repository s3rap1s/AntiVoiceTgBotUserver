#include <tg/types/transaction_partner_other.hpp>

#include "common.hpp"

namespace tg {

TransactionPartnerOther Parse(const Value& value, To<TransactionPartnerOther>) {
    TransactionPartnerOther obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

}  // namespace tg
