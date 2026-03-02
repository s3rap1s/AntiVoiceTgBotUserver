#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct GiveawayCreated {
    Optional<Integer> prize_star_count;
};

GiveawayCreated Parse(const Value& value, To<GiveawayCreated>);

}  // namespace tg
