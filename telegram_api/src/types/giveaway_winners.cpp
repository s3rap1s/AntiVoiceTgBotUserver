#include <tg/types/chat.hpp>
#include <tg/types/giveaway_winners.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

GiveawayWinners Parse(const Value& value, To<GiveawayWinners>) {
    GiveawayWinners obj{};
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.giveaway_message_id = ParseComplex<Integer>(value["giveaway_message_id"]);
    obj.winners_selection_date = ParseComplex<Integer>(value["winners_selection_date"]);
    obj.winner_count = ParseComplex<Integer>(value["winner_count"]);
    obj.winners = ParseComplex<Array<User>>(value["winners"]);
    obj.additional_chat_count = ParseComplex<Optional<Integer>>(value["additional_chat_count"]);
    obj.prize_star_count = ParseComplex<Optional<Integer>>(value["prize_star_count"]);
    obj.premium_subscription_month_count = ParseComplex<Optional<Integer>>(value["premium_subscription_month_count"]);
    obj.unclaimed_prize_count = ParseComplex<Optional<Integer>>(value["unclaimed_prize_count"]);
    obj.only_new_members = ParseComplex<OptionalTrue>(value["only_new_members"]);
    obj.was_refunded = ParseComplex<OptionalTrue>(value["was_refunded"]);
    obj.prize_description = ParseComplex<Optional<String>>(value["prize_description"]);
    return obj;
}

void Serialize(const GiveawayWinners& obj, ValueBuilder& builder) {
    internal::Put(builder, "chat", obj.chat);
    internal::Put(builder, "giveaway_message_id", obj.giveaway_message_id);
    internal::Put(builder, "winners_selection_date", obj.winners_selection_date);
    internal::Put(builder, "winner_count", obj.winner_count);
    internal::Put(builder, "winners", obj.winners);
    internal::Put(builder, "additional_chat_count", obj.additional_chat_count);
    internal::Put(builder, "prize_star_count", obj.prize_star_count);
    internal::Put(builder, "premium_subscription_month_count", obj.premium_subscription_month_count);
    internal::Put(builder, "unclaimed_prize_count", obj.unclaimed_prize_count);
    internal::Put(builder, "only_new_members", obj.only_new_members);
    internal::Put(builder, "was_refunded", obj.was_refunded);
    internal::Put(builder, "prize_description", obj.prize_description);
}

}  // namespace tg
