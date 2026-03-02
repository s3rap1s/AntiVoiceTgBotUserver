#pragma once

#include <tg/types/chat.hpp>
#include <tg/types/common.hpp>

namespace tg {

struct MessageOriginChat {
    String type;
    Integer date;
    Chat sender_chat;
    Optional<String> author_signature;
};

MessageOriginChat Parse(const Value& value, To<MessageOriginChat>);

}  // namespace tg
