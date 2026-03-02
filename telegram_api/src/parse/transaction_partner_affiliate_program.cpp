#include <tg/types/transaction_partner_affiliate_program.hpp>
#include <tg/types/user.hpp>

#include "common.hpp"

namespace tg {

TransactionPartnerAffiliateProgram Parse(
    const Value& value, To<TransactionPartnerAffiliateProgram>) {
    TransactionPartnerAffiliateProgram obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.sponsor_user = ParseComplex<Optional<User>>(value["sponsor_user"]);
    obj.commission_per_mille =
        ParseComplex<Integer>(value["commission_per_mille"]);
    return obj;
}

}  // namespace tg
