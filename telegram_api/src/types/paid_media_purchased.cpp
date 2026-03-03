#include <tg/types/paid_media_purchased.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

PaidMediaPurchased Parse(const Value& value, To<PaidMediaPurchased>) {
    PaidMediaPurchased obj{};
    obj.from = ParseComplex<User>(value["from"]);
    obj.paid_media_payload = ParseComplex<String>(value["paid_media_payload"]);
    return obj;
}

void Serialize(const PaidMediaPurchased& obj, ValueBuilder& builder) {
    internal::Put(builder, "from", obj.from);
    internal::Put(builder, "paid_media_payload", obj.paid_media_payload);
}

}  // namespace tg
