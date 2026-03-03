#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct GiveawayCreated {
    Optional<Integer> prize_star_count;
};

GiveawayCreated Parse(const Value& value, To<GiveawayCreated>);

void Serialize(const GiveawayCreated& obj, ValueBuilder& builder);

}  // namespace tg
