#include <types/owned_gift.hpp>
#include <types/owned_gift_regular.hpp>
#include <types/owned_gift_unique.hpp>

#include "common.hpp"

namespace tg {

OwnedGift Parse(const Value& value, To<OwnedGift>) {
    if (detail::IsPresent(value["send_date"]))
        return ParseComplex<OwnedGiftUnique>(value);
    return ParseComplex<OwnedGiftRegular>(value);
}

}  // namespace tg
