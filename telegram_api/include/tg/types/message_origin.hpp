#pragma once

#include <userver/formats/json/value_builder.hpp>

#include "message_origin_channel.hpp"
#include "message_origin_chat.hpp"
#include "message_origin_hidden_user.hpp"
#include "message_origin_user.hpp"

namespace tg {

using ValueBuilder = userver::formats::json::ValueBuilder;

using MessageOrigin = OneOf<MessageOriginUser, MessageOriginHiddenUser, MessageOriginChat, MessageOriginChannel>;

MessageOrigin Parse(const Value& value, To<MessageOrigin>);

void Serialize(const MessageOrigin& obj, ValueBuilder& builder);

}  // namespace tg
