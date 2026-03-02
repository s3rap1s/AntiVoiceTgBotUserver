#pragma once

#include <tg/types/common.hpp>
#include <tg/types/chat_boost.hpp>

namespace tg {

struct UserChatBoosts {
    Array<ChatBoost> boosts;
};

UserChatBoosts Parse(const Value& value, To<UserChatBoosts>);

}  // namespace tg
