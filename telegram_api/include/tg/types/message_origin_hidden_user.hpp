#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct MessageOriginHiddenUser {
    String type;
    Integer date;
    String sender_user_name;
};

MessageOriginHiddenUser Parse(const Value& value, To<MessageOriginHiddenUser>);

void Serialize(const MessageOriginHiddenUser& obj, ValueBuilder& builder);

}  // namespace tg
