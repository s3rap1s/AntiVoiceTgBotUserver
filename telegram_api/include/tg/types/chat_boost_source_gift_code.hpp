#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ChatBoostSourceGiftCode {
    String source;
    User user;
};

ChatBoostSourceGiftCode Parse(const Value& value, To<ChatBoostSourceGiftCode>);

void Serialize(const ChatBoostSourceGiftCode& obj, ValueBuilder& builder);

}  // namespace tg
