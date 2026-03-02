#pragma once

#include <types/common.hpp>
#include <types/owned_gift_regular.hpp>
#include <types/owned_gift_unique.hpp>

namespace tg {

using OwnedGift = OneOf<OwnedGiftRegular, OwnedGiftUnique>;

OwnedGift Parse(const Value& value, To<OwnedGift>);

}  // namespace tg
