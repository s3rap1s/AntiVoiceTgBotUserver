#pragma once

#include "message_origin_channel.hpp"
#include "message_origin_chat.hpp"
#include "message_origin_hidden_user.hpp"
#include "message_origin_user.hpp"

namespace tg {

using MessageOrigin = OneOf<MessageOriginUser, MessageOriginHiddenUser,
                            MessageOriginChat, MessageOriginChannel>;

MessageOrigin Parse(const Value& value, To<MessageOrigin>);

}  // namespace tg
