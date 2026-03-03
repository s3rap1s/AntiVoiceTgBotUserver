#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ChatOwnerChanged {
    Optional<User> new_owner;
};

ChatOwnerChanged Parse(const Value& value, To<ChatOwnerChanged>);

void Serialize(const ChatOwnerChanged& obj, ValueBuilder& builder);

}  // namespace tg
