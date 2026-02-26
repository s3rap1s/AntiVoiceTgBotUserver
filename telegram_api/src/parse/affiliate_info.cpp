#include <types/affiliate_info.hpp>

#include <parse/common.hpp>

namespace tg {

AffiliateInfo Parse(const Value& value, To<AffiliateInfo>) {
    AffiliateInfo obj{};
    obj.affiliate_user = ParseComplex<User>(value["affiliate_user"]);
    obj.affiliate_chat = ParseComplex<Chat>(value["affiliate_chat"]);
    obj.commission_per_mille =
        ParseComplex<Integer>(value["commission_per_mille"]);
    obj.amount = ParseComplex<Integer>(value["amount"]);
    obj.nanostar_amount = ParseOptional<Integer>(value["nanostar_amount"]);
    return obj;
}

}  // namespace tg
