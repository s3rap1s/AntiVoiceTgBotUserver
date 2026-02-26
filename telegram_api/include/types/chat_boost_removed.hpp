#pragma once

#include "chat.hpp"
#include "chat_boost_source.hpp"
#include "common.hpp"

namespace tg {

struct ChatBoostRemoved {
    Chat chat;
    String boost_id;
    Integer remove_date;
    ChatBoostSource source;
};

ChatBoostRemoved Parse(const Value& value, To<ChatBoostRemoved>);

}  // namespace tg
