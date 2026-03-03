#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/owned_gift_regular.hpp>
#include <tg/types/owned_gift_unique.hpp>

namespace tg {

using OwnedGift = OneOf<OwnedGiftRegular, OwnedGiftUnique>;

OwnedGift Parse(const Value& value, To<OwnedGift>);

void Serialize(const OwnedGift& obj, ValueBuilder& builder);

}  // namespace tg
