#pragma once

#include "common.hpp"
#include "owned_gift.hpp"

namespace tg {

struct OwnedGifts {
    Integer total_count;
    Array<OwnedGift> gifts;
    Optional<String> next_offset;
};

OwnedGifts Parse(const Value& value, To<OwnedGifts>);

}  // namespace tg
