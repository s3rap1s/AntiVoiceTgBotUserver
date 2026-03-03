#include <tg/types/giveaway_completed.hpp>
#include <tg/types/message.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

GiveawayCompleted Parse(const Value& value, To<GiveawayCompleted>) {
    GiveawayCompleted obj{};
    obj.winner_count = ParseComplex<Integer>(value["winner_count"]);
    obj.unclaimed_prize_count = ParseComplex<Optional<Integer>>(value["unclaimed_prize_count"]);
    obj.giveaway_message = ParseComplex<MessagePtr>(value["giveaway_message"]);
    obj.is_star_giveaway = ParseComplex<OptionalTrue>(value["is_star_giveaway"]);
    return obj;
}

void Serialize(const GiveawayCompleted& obj, ValueBuilder& builder) {
    internal::Put(builder, "winner_count", obj.winner_count);
    internal::Put(builder, "unclaimed_prize_count", obj.unclaimed_prize_count);
    internal::Put(builder, "giveaway_message", obj.giveaway_message);
    internal::Put(builder, "is_star_giveaway", obj.is_star_giveaway);
}

}  // namespace tg
