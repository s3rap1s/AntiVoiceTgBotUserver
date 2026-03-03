#pragma once

#include <userver/formats/json/value_builder.hpp>

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

void Serialize(const MessageOriginChat& obj, ValueBuilder& builder);

}  // namespace tg
