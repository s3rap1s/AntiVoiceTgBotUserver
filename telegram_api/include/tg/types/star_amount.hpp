#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct StarAmount {
    Integer amount;
    Optional<Integer> nanostar_amount;
};

StarAmount Parse(const Value& value, To<StarAmount>);

void Serialize(const StarAmount& obj, ValueBuilder& builder);

}  // namespace tg
