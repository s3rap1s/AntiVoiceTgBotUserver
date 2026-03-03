#include <tg/types/owned_gift.hpp>
#include <tg/types/owned_gift_regular.hpp>
#include <tg/types/owned_gift_unique.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

OwnedGift Parse(const Value& value, To<OwnedGift>) {
    if (internal::IsPresent(value["send_date"])) return ParseComplex<OwnedGiftUnique>(value);
    return ParseComplex<OwnedGiftRegular>(value);
}

void Serialize(const OwnedGift& obj, ValueBuilder& builder) { internal::Set(builder, obj); }

}  // namespace tg
