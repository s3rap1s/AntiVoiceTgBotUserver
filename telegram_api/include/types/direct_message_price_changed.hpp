#pragma once

#include "common.hpp"

namespace tg {

struct DirectMessagePriceChanged {
    Optional<Boolean> are_direct_message_enabled;
    Optional<Integer> direct_message_star_count;
};

DirectMessagePriceChanged Parse(const Value& value,
                                To<DirectMessagePriceChanged>);

}  // namespace tg
