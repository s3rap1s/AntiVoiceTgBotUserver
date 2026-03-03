#include <tg/types/giveaway_created.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

GiveawayCreated Parse(const Value& value, To<GiveawayCreated>) {
    GiveawayCreated obj{};
    obj.prize_star_count = ParseComplex<Optional<Integer>>(value["prize_star_count"]);
    return obj;
}

void Serialize(const GiveawayCreated& obj, ValueBuilder& builder) {
    internal::Put(builder, "prize_star_count", obj.prize_star_count);
}

}  // namespace tg
