#pragma once

#include <userver/formats/json/value_builder.hpp>

#include "chat.hpp"
#include "chat_boost.hpp"

namespace tg {

using ValueBuilder = userver::formats::json::ValueBuilder;

struct ChatBoostUpdated {
    Chat chat;
    ChatBoost boost;
};

ChatBoostUpdated Parse(const Value& value, To<ChatBoostUpdated>);

void Serialize(const ChatBoostUpdated& obj, ValueBuilder& builder);

}  // namespace tg
