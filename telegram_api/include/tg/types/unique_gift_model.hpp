#pragma once

#include <tg/types/common.hpp>
#include <tg/types/sticker.hpp>

namespace tg {

struct UniqueGiftModel {
    String name;
    Sticker sticker;
    Integer rarity_per_mille;
    Optional<String> rarity;
};

UniqueGiftModel Parse(const Value& value, To<UniqueGiftModel>);

}  // namespace tg
