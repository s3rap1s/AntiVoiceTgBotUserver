#include <tg/types/direct_message_price_changed.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

DirectMessagePriceChanged Parse(const Value& value, To<DirectMessagePriceChanged>) {
    DirectMessagePriceChanged obj{};
    obj.are_direct_message_enabled = ParseComplex<Optional<Boolean>>(value["are_direct_message_enabled"]);
    obj.direct_message_star_count = ParseComplex<Optional<Integer>>(value["direct_message_star_count"]);
    return obj;
}

void Serialize(const DirectMessagePriceChanged& obj, ValueBuilder& builder) {
    internal::Put(builder, "are_direct_message_enabled", obj.are_direct_message_enabled);
    internal::Put(builder, "direct_message_star_count", obj.direct_message_star_count);
}

}  // namespace tg
