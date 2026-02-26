#pragma once

#include "chat_boost.hpp"
#include "common.hpp"

namespace tg {

struct UserChatBoosts {
    Array<ChatBoost> boosts;
};

UserChatBoosts Parse(const Value& value, To<UserChatBoosts>);

}  // namespace tg
