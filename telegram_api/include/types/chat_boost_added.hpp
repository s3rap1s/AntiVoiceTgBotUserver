#pragma once

#include "common.hpp"

namespace tg {

struct ChatBoostAdded {
    Integer boost_count;
};

ChatBoostAdded Parse(const Value& value, To<ChatBoostAdded>);

}  // namespace tg
