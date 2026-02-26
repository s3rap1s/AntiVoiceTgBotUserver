#pragma once

#include "common.hpp"
#include "sticker.hpp"

namespace tg {

struct UniqueGiftSymbol {
    String name;
    Sticker sticker;
    Integer rarity_per_mille;
};

UniqueGiftSymbol Parse(const Value& value, To<UniqueGiftSymbol>);

}  // namespace tg
