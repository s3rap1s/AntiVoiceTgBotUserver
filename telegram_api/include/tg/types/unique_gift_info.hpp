#pragma once

#include <tg/types/common.hpp>
#include <tg/types/unique_gift.hpp>

namespace tg {

struct UniqueGiftInfo {
    UniqueGift gift;
    String origin;
    Optional<Integer> last_resale_star_count;
    Optional<String> owned_gift_id;
    Optional<Integer> transfer_star_count;
    Optional<Integer> next_transfer_date;
};

UniqueGiftInfo Parse(const Value& value, To<UniqueGiftInfo>);

}  // namespace tg
