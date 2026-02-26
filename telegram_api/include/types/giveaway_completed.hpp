#pragma once

#include "common.hpp"

namespace tg {

struct Message;

struct GiveawayCompleted {
    Integer winner_count;
    Optional<Integer> unclaimed_prize_count;
    Ptr<Message> giveaway_message;
    OptionalTrue is_star_giveaway;
};

GiveawayCompleted Parse(const Value& value, To<GiveawayCompleted>);

}  // namespace tg
