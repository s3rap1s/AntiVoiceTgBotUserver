#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include "user.hpp"

namespace tg {

struct ChatBoostSourcePremium {
    String source;
    User user;
};

ChatBoostSourcePremium Parse(const Value& value, To<ChatBoostSourcePremium>);

void Serialize(const ChatBoostSourcePremium& obj, ValueBuilder& builder);

}  // namespace tg
