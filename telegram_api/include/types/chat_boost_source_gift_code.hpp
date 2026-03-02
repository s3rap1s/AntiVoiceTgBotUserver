#pragma once

#include <types/common.hpp>
#include <types/user.hpp>

namespace tg {

struct ChatBoostSourceGiftCode {
    String source;
    User user;
};

ChatBoostSourceGiftCode Parse(const Value& value, To<ChatBoostSourceGiftCode>);

}  // namespace tg
