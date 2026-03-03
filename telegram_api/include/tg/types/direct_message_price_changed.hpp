#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct DirectMessagePriceChanged {
    Optional<Boolean> are_direct_message_enabled;
    Optional<Integer> direct_message_star_count;
};

DirectMessagePriceChanged Parse(const Value& value, To<DirectMessagePriceChanged>);

void Serialize(const DirectMessagePriceChanged& obj, ValueBuilder& builder);

}  // namespace tg
