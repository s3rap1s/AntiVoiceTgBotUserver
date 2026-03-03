#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct MessageAutoDeleteTimerChanged {
    Integer message_auto_delete_time;
};

MessageAutoDeleteTimerChanged Parse(const Value& value, To<MessageAutoDeleteTimerChanged>);

void Serialize(const MessageAutoDeleteTimerChanged& obj, ValueBuilder& builder);

}  // namespace tg
