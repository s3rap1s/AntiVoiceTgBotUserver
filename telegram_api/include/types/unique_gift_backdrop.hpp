#pragma once

#include "common.hpp"
#include "unique_gift_backdrop_colors.hpp"

namespace tg {

struct UniqueGiftBackdrop {
    String name;
    UniqueGiftBackdropColors colors;
    Integer rarity_per_mille;
};

UniqueGiftBackdrop Parse(const Value& value, To<UniqueGiftBackdrop>);

}  // namespace tg
