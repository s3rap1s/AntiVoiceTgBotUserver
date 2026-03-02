#pragma once

#include <types/chat.hpp>
#include <types/common.hpp>
#include <types/user.hpp>

namespace tg {

struct GiveawayWinners {
    Chat chat;
    Integer giveaway_message_id;
    Integer winners_selection_date;
    Integer winner_count;
    Array<User> winners;
    Optional<Integer> additional_chat_count;
    Optional<Integer> prize_star_count;
    Optional<Integer> premium_subscription_month_count;
    Optional<Integer> unclaimed_prize_count;
    OptionalTrue only_new_members;
    OptionalTrue was_refunded;
    Optional<String> prize_description;
};

GiveawayWinners Parse(const Value& value, To<GiveawayWinners>);

}  // namespace tg
