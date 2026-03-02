#pragma once

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ChatBoostSourceGiftCode {
    String source;
    User user;
};

ChatBoostSourceGiftCode Parse(const Value& value, To<ChatBoostSourceGiftCode>);

}  // namespace tg
