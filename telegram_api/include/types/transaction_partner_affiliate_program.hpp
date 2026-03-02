#pragma once

#include <types/common.hpp>
#include <types/user.hpp>

namespace tg {

struct TransactionPartnerAffiliateProgram {
    String type;
    Optional<User> sponsor_user;
    Integer commission_per_mille;
};

TransactionPartnerAffiliateProgram Parse(
    const Value& value, To<TransactionPartnerAffiliateProgram>);

}  // namespace tg
