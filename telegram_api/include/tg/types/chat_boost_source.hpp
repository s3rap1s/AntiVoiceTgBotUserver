#pragma once

#include <tg/types/chat_boost_source_gift_code.hpp>
#include <tg/types/chat_boost_source_giveaway.hpp>
#include <tg/types/chat_boost_source_premium.hpp>
#include <tg/types/common.hpp>

namespace tg {

using ChatBoostSource = OneOf<ChatBoostSourcePremium, ChatBoostSourceGiftCode,
                              ChatBoostSourceGiveaway>;

ChatBoostSource Parse(const Value& value, To<ChatBoostSource>);

}  // namespace tg
