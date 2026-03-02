#pragma once

#include <tg/types/chat_boost_source.hpp>
#include <tg/types/common.hpp>

namespace tg {

struct ChatBoost {
    String boost_id;
    Integer add_date;
    Integer expiration_date;
    ChatBoostSource source;
};

ChatBoost Parse(const Value& value, To<ChatBoost>);

}  // namespace tg
