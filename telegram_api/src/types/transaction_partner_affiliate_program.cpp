#include <tg/types/transaction_partner_affiliate_program.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

TransactionPartnerAffiliateProgram Parse(const Value& value, To<TransactionPartnerAffiliateProgram>) {
    TransactionPartnerAffiliateProgram obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.sponsor_user = ParseComplex<Optional<User>>(value["sponsor_user"]);
    obj.commission_per_mille = ParseComplex<Integer>(value["commission_per_mille"]);
    return obj;
}

void Serialize(const TransactionPartnerAffiliateProgram& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "sponsor_user", obj.sponsor_user);
    internal::Put(builder, "commission_per_mille", obj.commission_per_mille);
}

}  // namespace tg
