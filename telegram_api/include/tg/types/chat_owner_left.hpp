#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ChatOwnerLeft {
    Optional<User> new_owner;
};

ChatOwnerLeft Parse(const Value& value, To<ChatOwnerLeft>);

void Serialize(const ChatOwnerLeft& obj, ValueBuilder& builder);

}  // namespace tg
