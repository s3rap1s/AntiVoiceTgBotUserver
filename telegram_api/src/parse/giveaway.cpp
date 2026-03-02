#include <types/chat.hpp>
#include <types/giveaway.hpp>

#include "common.hpp"

namespace tg {

Giveaway Parse(const Value& value, To<Giveaway>) {
    Giveaway obj{};
    obj.chats = ParseComplex<Array<Chat>>(value["chats"]);
    obj.winners_selection_date =
        ParseComplex<Integer>(value["winners_selection_date"]);
    obj.winner_count = ParseComplex<Integer>(value["winner_count"]);
    obj.only_new_members =
        ParseComplex<OptionalTrue>(value["only_new_members"]);
    obj.has_public_winners =
        ParseComplex<OptionalTrue>(value["has_public_winners"]);
    obj.prize_description =
        ParseComplex<Optional<String>>(value["prize_description"]);
    obj.country_codes =
        ParseComplex<Optional<Array<String>>>(value["country_codes"]);
    obj.prize_star_count =
        ParseComplex<Optional<Integer>>(value["prize_star_count"]);
    obj.premium_subscription_month_count = ParseComplex<Optional<Integer>>(
        value["premium_subscription_month_count"]);
    return obj;
}

}  // namespace tg
