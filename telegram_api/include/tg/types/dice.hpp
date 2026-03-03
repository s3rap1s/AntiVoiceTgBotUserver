#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct Dice {
    String emoji;
    Integer value;
};

Dice Parse(const Value& value, To<Dice>);

void Serialize(const Dice& obj, ValueBuilder& builder);

}  // namespace tg
