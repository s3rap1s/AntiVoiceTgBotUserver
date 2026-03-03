#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/unique_gift_backdrop_colors.hpp>

namespace tg {

struct UniqueGiftBackdrop {
    String name;
    UniqueGiftBackdropColors colors;
    Integer rarity_per_mille;
};

UniqueGiftBackdrop Parse(const Value& value, To<UniqueGiftBackdrop>);

void Serialize(const UniqueGiftBackdrop& obj, ValueBuilder& builder);

}  // namespace tg
