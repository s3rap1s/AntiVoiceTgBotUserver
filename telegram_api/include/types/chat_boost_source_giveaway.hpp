#pragma once

#include "common.hpp"
#include "user.hpp"

namespace tg {

struct ChatBoostSourceGiveaway {
    String source;
    Integer giveaway_message_id;
    Optional<User> user;
    Optional<Integer> prize_star_count;
    OptionalTrue is_unclaimed;
};

ChatBoostSourceGiveaway Parse(const Value& value, To<ChatBoostSourceGiveaway>);

}  // namespace tg
