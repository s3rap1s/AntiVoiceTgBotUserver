#include <tg/types/transaction_partner_other.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

TransactionPartnerOther Parse(const Value& value, To<TransactionPartnerOther>) {
    TransactionPartnerOther obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

void Serialize(const TransactionPartnerOther& obj, ValueBuilder& builder) { internal::Put(builder, "type", obj.type); }

}  // namespace tg
