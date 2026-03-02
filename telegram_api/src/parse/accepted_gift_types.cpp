#include <tg/types/accepted_gift_types.hpp>

#include "common.hpp"

namespace tg {

AcceptedGiftTypes Parse(const Value& value, To<AcceptedGiftTypes>) {
    AcceptedGiftTypes obj{};
    obj.unlimited_gifts = ParseComplex<Boolean>(value["unlimited_gifts"]);
    obj.limited_gifts = ParseComplex<Boolean>(value["limited_gifts"]);
    obj.unique_gifts = ParseComplex<Boolean>(value["unique_gifts"]);
    obj.premium_subscription =
        ParseComplex<Boolean>(value["premium_subscription"]);
    obj.gifts_from_channels =
        ParseComplex<Boolean>(value["gifts_from_channels"]);
    return obj;
}

}  // namespace tg
