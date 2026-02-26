#pragma once

#include "common.hpp"
#include "user.hpp"

namespace tg {

struct ChatBoostSourcePremium {
    String source;
    User user;
};

ChatBoostSourcePremium Parse(const Value& value, To<ChatBoostSourcePremium>);

}  // namespace tg
