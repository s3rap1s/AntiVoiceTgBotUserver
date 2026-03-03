#include <tg/types/chat.hpp>
#include <tg/types/giveaway.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

Giveaway Parse(const Value& value, To<Giveaway>) {
    Giveaway obj{};
    obj.chats = ParseComplex<Array<Chat>>(value["chats"]);
    obj.winners_selection_date = ParseComplex<Integer>(value["winners_selection_date"]);
    obj.winner_count = ParseComplex<Integer>(value["winner_count"]);
    obj.only_new_members = ParseComplex<OptionalTrue>(value["only_new_members"]);
    obj.has_public_winners = ParseComplex<OptionalTrue>(value["has_public_winners"]);
    obj.prize_description = ParseComplex<Optional<String>>(value["prize_description"]);
    obj.country_codes = ParseComplex<Optional<Array<String>>>(value["country_codes"]);
    obj.prize_star_count = ParseComplex<Optional<Integer>>(value["prize_star_count"]);
    obj.premium_subscription_month_count = ParseComplex<Optional<Integer>>(value["premium_subscription_month_count"]);
    return obj;
}

void Serialize(const Giveaway& obj, ValueBuilder& builder) {
    internal::Put(builder, "chats", obj.chats);
    internal::Put(builder, "winners_selection_date", obj.winners_selection_date);
    internal::Put(builder, "winner_count", obj.winner_count);
    internal::Put(builder, "only_new_members", obj.only_new_members);
    internal::Put(builder, "has_public_winners", obj.has_public_winners);
    internal::Put(builder, "prize_description", obj.prize_description);
    internal::Put(builder, "country_codes", obj.country_codes);
    internal::Put(builder, "prize_star_count", obj.prize_star_count);
    internal::Put(builder, "premium_subscription_month_count", obj.premium_subscription_month_count);
}

}  // namespace tg
