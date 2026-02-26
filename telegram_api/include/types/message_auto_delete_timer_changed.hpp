#pragma once

#include "common.hpp"

namespace tg {

struct MessageAutoDeleteTimerChanged {
    Integer message_auto_delete_time;
};

MessageAutoDeleteTimerChanged Parse(const Value& value,
                                    To<MessageAutoDeleteTimerChanged>);

}  // namespace tg
