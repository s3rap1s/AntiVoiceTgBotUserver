#pragma once

#include <types/chat.hpp>
#include <types/chat_boost_source.hpp>
#include <types/common.hpp>

namespace tg {

struct ChatBoostRemoved {
    Chat chat;
    String boost_id;
    Integer remove_date;
    ChatBoostSource source;
};

ChatBoostRemoved Parse(const Value& value, To<ChatBoostRemoved>);

}  // namespace tg
