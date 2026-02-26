#pragma once

#include "chat_boost_source_gift_code.hpp"
#include "chat_boost_source_giveaway.hpp"
#include "chat_boost_source_premium.hpp"
#include "common.hpp"

namespace tg {

using ChatBoostSource = OneOf<ChatBoostSourcePremium, ChatBoostSourceGiftCode,
                              ChatBoostSourceGiveaway>;

ChatBoostSource Parse(const Value& value, To<ChatBoostSource>);

}  // namespace tg
