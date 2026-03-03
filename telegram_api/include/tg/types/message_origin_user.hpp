#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct MessageOriginUser {
    String type;
    Integer date;
    User sender_user;
};

MessageOriginUser Parse(const Value& value, To<MessageOriginUser>);

void Serialize(const MessageOriginUser& obj, ValueBuilder& builder);

}  // namespace tg
