#pragma once

#include "common.hpp"
#include "unique_gift.hpp"

namespace tg {

struct UniqueGiftInfo {
    UniqueGift gift;
    String origin;
    Optional<String> last_resale_currency;
    Optional<Integer> last_resale_amount;
    Optional<String> owned_gift_id;
    Optional<Integer> transfer_star_count;
    Optional<Integer> next_transfer_date;
};

UniqueGiftInfo Parse(const Value& value, To<UniqueGiftInfo>);

}  // namespace tg
