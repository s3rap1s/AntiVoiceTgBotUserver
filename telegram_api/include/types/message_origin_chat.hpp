#pragma once

#include <types/chat.hpp>
#include <types/common.hpp>

namespace tg {

struct MessageOriginChat {
    String type;
    Integer date;
    Chat sender_chat;
    Optional<String> author_signature;
};

MessageOriginChat Parse(const Value& value, To<MessageOriginChat>);

}  // namespace tg
