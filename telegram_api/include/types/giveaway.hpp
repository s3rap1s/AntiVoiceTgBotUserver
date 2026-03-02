#pragma once

#include <types/chat.hpp>
#include <types/common.hpp>

namespace tg {

struct Giveaway {
    Array<Chat> chats;
    Integer winners_selection_date;
    Integer winner_count;
    OptionalTrue only_new_members;
    OptionalTrue has_public_winners;
    Optional<String> prize_description;
    Optional<Array<String>> country_codes;
    Optional<Integer> prize_star_count;
    Optional<Integer> premium_subscription_month_count;
};

Giveaway Parse(const Value& value, To<Giveaway>);

}  // namespace tg
