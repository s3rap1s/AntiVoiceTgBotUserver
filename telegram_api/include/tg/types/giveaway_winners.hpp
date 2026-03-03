#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/chat.hpp>
#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

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

void Serialize(const GiveawayWinners& obj, ValueBuilder& builder);

}  // namespace tg
