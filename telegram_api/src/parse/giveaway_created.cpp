#include <tg/types/giveaway_created.hpp>

#include "common.hpp"

namespace tg {

GiveawayCreated Parse(const Value& value, To<GiveawayCreated>) {
    GiveawayCreated obj{};
    obj.prize_star_count =
        ParseComplex<Optional<Integer>>(value["prize_star_count"]);
    return obj;
}

}  // namespace tg
