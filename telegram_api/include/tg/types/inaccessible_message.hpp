#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/chat.hpp>
#include <tg/types/common.hpp>

namespace tg {

struct InaccessibleMessage {
    Chat chat;
    Integer message_id;
    Integer date;
};

InaccessibleMessage Parse(const Value& value, To<InaccessibleMessage>);

void Serialize(const InaccessibleMessage& obj, ValueBuilder& builder);

}  // namespace tg
