#include <tg/types/giveaway_completed.hpp>
#include <tg/types/message.hpp>

#include "common.hpp"

namespace tg {

GiveawayCompleted Parse(const Value& value, To<GiveawayCompleted>) {
    GiveawayCompleted obj{};
    obj.winner_count = ParseComplex<Integer>(value["winner_count"]);
    obj.unclaimed_prize_count =
        ParseComplex<Optional<Integer>>(value["unclaimed_prize_count"]);
    obj.giveaway_message = ParseComplex<MessagePtr>(value["giveaway_message"]);
    obj.is_star_giveaway =
        ParseComplex<OptionalTrue>(value["is_star_giveaway"]);
    return obj;
}

}  // namespace tg
