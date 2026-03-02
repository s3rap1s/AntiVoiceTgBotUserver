#include <tg/types/paid_media_purchased.hpp>
#include <tg/types/user.hpp>

#include "common.hpp"

namespace tg {

PaidMediaPurchased Parse(const Value& value, To<PaidMediaPurchased>) {
    PaidMediaPurchased obj{};
    obj.from = ParseComplex<User>(value["from"]);
    obj.paid_media_payload = ParseComplex<String>(value["paid_media_payload"]);
    return obj;
}

}  // namespace tg
