#pragma once

#include "chat.hpp"
#include "chat_boost.hpp"

namespace tg {

struct ChatBoostUpdated {
    Chat chat;
    ChatBoost boost;
};

ChatBoostUpdated Parse(const Value& value, To<ChatBoostUpdated>);

}  // namespace tg
