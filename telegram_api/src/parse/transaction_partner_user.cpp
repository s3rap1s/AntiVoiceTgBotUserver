#include <types/affiliate_info.hpp>
#include <types/gift.hpp>
#include <types/paid_media.hpp>
#include <types/transaction_partner_user.hpp>
#include <types/user.hpp>

#include "common.hpp"

namespace tg {

TransactionPartnerUser Parse(const Value& value, To<TransactionPartnerUser>) {
    TransactionPartnerUser obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.transaction_type = ParseComplex<String>(value["transaction_type"]);
    obj.user = ParseComplex<User>(value["user"]);
    obj.affiliate = ParseComplex<Optional<AffiliateInfo>>(value["affiliate"]);
    obj.invoice_payload =
        ParseComplex<Optional<String>>(value["invoice_payload"]);
    obj.subscription_period =
        ParseComplex<Optional<Integer>>(value["subscription_period"]);
    obj.paid_media =
        ParseComplex<Optional<Array<PaidMedia>>>(value["paid_media"]);
    obj.paid_media_payload =
        ParseComplex<Optional<String>>(value["paid_media_payload"]);
    obj.gift = ParseComplex<Optional<Gift>>(value["gift"]);
    obj.premium_subscription_duration =
        ParseComplex<Optional<Integer>>(value["premium_subscription_duration"]);
    return obj;
}

}  // namespace tg
