#pragma once

#include <types/common.hpp>
#include <types/chat_boost.hpp>

namespace tg {

struct UserChatBoosts {
    Array<ChatBoost> boosts;
};

UserChatBoosts Parse(const Value& value, To<UserChatBoosts>);

}  // namespace tg
