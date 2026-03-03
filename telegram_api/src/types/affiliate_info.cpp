#include <tg/types/affiliate_info.hpp>
#include <tg/types/chat.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

AffiliateInfo Parse(const Value& value, To<AffiliateInfo>) {
    AffiliateInfo obj{};
    obj.affiliate_user = ParseComplex<User>(value["affiliate_user"]);
    obj.affiliate_chat = ParseComplex<Chat>(value["affiliate_chat"]);
    obj.commission_per_mille = ParseComplex<Integer>(value["commission_per_mille"]);
    obj.amount = ParseComplex<Integer>(value["amount"]);
    obj.nanostar_amount = ParseComplex<Optional<Integer>>(value["nanostar_amount"]);
    return obj;
}

void Serialize(const AffiliateInfo& obj, ValueBuilder& builder) {
    internal::Put(builder, "affiliate_user", obj.affiliate_user);
    internal::Put(builder, "affiliate_chat", obj.affiliate_chat);
    internal::Put(builder, "commission_per_mille", obj.commission_per_mille);
    internal::Put(builder, "amount", obj.amount);
    internal::Put(builder, "nanostar_amount", obj.nanostar_amount);
}

}  // namespace tg
