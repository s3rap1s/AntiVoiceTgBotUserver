#include <tg/types/chat.hpp>
#include <tg/types/giveaway_winners.hpp>
#include <tg/types/user.hpp>

#include "common.hpp"

namespace tg {

GiveawayWinners Parse(const Value& value, To<GiveawayWinners>) {
    GiveawayWinners obj{};
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.giveaway_message_id =
        ParseComplex<Integer>(value["giveaway_message_id"]);
    obj.winners_selection_date =
        ParseComplex<Integer>(value["winners_selection_date"]);
    obj.winner_count = ParseComplex<Integer>(value["winner_count"]);
    obj.winners = ParseComplex<Array<User>>(value["winners"]);
    obj.additional_chat_count =
        ParseComplex<Optional<Integer>>(value["additional_chat_count"]);
    obj.prize_star_count =
        ParseComplex<Optional<Integer>>(value["prize_star_count"]);
    obj.premium_subscription_month_count = ParseComplex<Optional<Integer>>(
        value["premium_subscription_month_count"]);
    obj.unclaimed_prize_count =
        ParseComplex<Optional<Integer>>(value["unclaimed_prize_count"]);
    obj.only_new_members =
        ParseComplex<OptionalTrue>(value["only_new_members"]);
    obj.was_refunded = ParseComplex<OptionalTrue>(value["was_refunded"]);
    obj.prize_description =
        ParseComplex<Optional<String>>(value["prize_description"]);
    return obj;
}

}  // namespace tg
