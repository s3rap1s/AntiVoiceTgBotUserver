#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/sticker.hpp>

namespace tg {

struct UniqueGiftSymbol {
    String name;
    Sticker sticker;
    Integer rarity_per_mille;
};

UniqueGiftSymbol Parse(const Value& value, To<UniqueGiftSymbol>);

void Serialize(const UniqueGiftSymbol& obj, ValueBuilder& builder);

}  // namespace tg
