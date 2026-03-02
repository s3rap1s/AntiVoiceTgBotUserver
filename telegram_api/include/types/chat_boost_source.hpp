#pragma once

#include <types/chat_boost_source_gift_code.hpp>
#include <types/chat_boost_source_giveaway.hpp>
#include <types/chat_boost_source_premium.hpp>
#include <types/common.hpp>

namespace tg {

using ChatBoostSource = OneOf<ChatBoostSourcePremium, ChatBoostSourceGiftCode,
                              ChatBoostSourceGiveaway>;

ChatBoostSource Parse(const Value& value, To<ChatBoostSource>);

}  // namespace tg
