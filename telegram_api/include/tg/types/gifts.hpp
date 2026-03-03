#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/gift.hpp>

namespace tg {

struct Gifts {
    Array<Gift> gifts;
};

Gifts Parse(const Value& value, To<Gifts>);

void Serialize(const Gifts& obj, ValueBuilder& builder);

}  // namespace tg
