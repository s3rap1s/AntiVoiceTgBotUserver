#include <tg/types/paid_message_price_changed.hpp>

#include "common.hpp"

namespace tg {

PaidMessagePriceChanged Parse(const Value& value, To<PaidMessagePriceChanged>) {
    PaidMessagePriceChanged obj{};
    obj.paid_message_star_count =
        ParseComplex<Integer>(value["paid_message_star_count"]);
    return obj;
}

}  // namespace tg
