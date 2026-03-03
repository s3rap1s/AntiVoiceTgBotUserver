#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/owned_gift.hpp>

namespace tg {

struct OwnedGifts {
    Integer total_count;
    Array<OwnedGift> gifts;
    Optional<String> next_offset;
};

OwnedGifts Parse(const Value& value, To<OwnedGifts>);

void Serialize(const OwnedGifts& obj, ValueBuilder& builder);

}  // namespace tg
