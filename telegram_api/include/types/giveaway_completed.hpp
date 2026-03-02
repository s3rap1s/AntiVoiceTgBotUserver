#pragma once

#include <types/common.hpp>
#include <types/message_ptr.hpp>

namespace tg {

struct GiveawayCompleted {
    Integer winner_count;
    Optional<Integer> unclaimed_prize_count;
    MessagePtr giveaway_message;
    OptionalTrue is_star_giveaway;
};

GiveawayCompleted Parse(const Value& value, To<GiveawayCompleted>);

}  // namespace tg
