#pragma once

#include "common.hpp"

namespace tg {

struct MessageId {
    Integer message_id;
};

MessageId Parse(const Value& value, To<MessageId>);

}  // namespace tg
