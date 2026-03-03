#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct PaidMessagePriceChanged {
    Integer paid_message_star_count;
};

PaidMessagePriceChanged Parse(const Value& value, To<PaidMessagePriceChanged>);

void Serialize(const PaidMessagePriceChanged& obj, ValueBuilder& builder);

}  // namespace tg
