#pragma once

#include "common.hpp"

namespace tg {

struct StarAmount {
    Integer amount;
    Optional<Integer> nanostar_amount;
};

StarAmount Parse(const Value& value, To<StarAmount>);

}  // namespace tg
