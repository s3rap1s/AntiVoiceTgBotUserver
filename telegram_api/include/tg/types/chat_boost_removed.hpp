#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/chat.hpp>
#include <tg/types/chat_boost_source.hpp>
#include <tg/types/common.hpp>

namespace tg {

struct ChatBoostRemoved {
    Chat chat;
    String boost_id;
    Integer remove_date;
    ChatBoostSource source;
};

ChatBoostRemoved Parse(const Value& value, To<ChatBoostRemoved>);

void Serialize(const ChatBoostRemoved& obj, ValueBuilder& builder);

}  // namespace tg
