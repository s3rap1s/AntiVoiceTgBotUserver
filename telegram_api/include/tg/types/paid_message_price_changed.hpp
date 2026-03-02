#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct PaidMessagePriceChanged {
    Integer paid_message_star_count;
};

PaidMessagePriceChanged Parse(const Value& value, To<PaidMessagePriceChanged>);

}  // namespace tg
