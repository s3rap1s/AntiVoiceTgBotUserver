#include <tg/types/accepted_gift_types.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

AcceptedGiftTypes Parse(const Value& value, To<AcceptedGiftTypes>) {
    AcceptedGiftTypes obj{};
    obj.unlimited_gifts = ParseComplex<Boolean>(value["unlimited_gifts"]);
    obj.limited_gifts = ParseComplex<Boolean>(value["limited_gifts"]);
    obj.unique_gifts = ParseComplex<Boolean>(value["unique_gifts"]);
    obj.premium_subscription = ParseComplex<Boolean>(value["premium_subscription"]);
    obj.gifts_from_channels = ParseComplex<Boolean>(value["gifts_from_channels"]);
    return obj;
}

void Serialize(const AcceptedGiftTypes& obj, ValueBuilder& builder) {
    internal::Put(builder, "unlimited_gifts", obj.unlimited_gifts);
    internal::Put(builder, "limited_gifts", obj.limited_gifts);
    internal::Put(builder, "unique_gifts", obj.unique_gifts);
    internal::Put(builder, "premium_subscription", obj.premium_subscription);
    internal::Put(builder, "gifts_from_channels", obj.gifts_from_channels);
}

}  // namespace tg
