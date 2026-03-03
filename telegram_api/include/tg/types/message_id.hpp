#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct MessageId {
    Integer message_id;
};

MessageId Parse(const Value& value, To<MessageId>);

void Serialize(const MessageId& obj, ValueBuilder& builder);

}  // namespace tg
