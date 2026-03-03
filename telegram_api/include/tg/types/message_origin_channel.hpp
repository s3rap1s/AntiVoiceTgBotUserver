#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/chat.hpp>
#include <tg/types/common.hpp>

namespace tg {

struct MessageOriginChannel {
    String type;
    Integer date;
    Chat chat;
    Integer message_id;
    Optional<String> author_signature;
};

MessageOriginChannel Parse(const Value& value, To<MessageOriginChannel>);

void Serialize(const MessageOriginChannel& obj, ValueBuilder& builder);

}  // namespace tg
