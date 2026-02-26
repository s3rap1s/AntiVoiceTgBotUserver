#pragma once

#include "common.hpp"

namespace tg {

struct VideoChatScheduled {
    Integer start_date;
};

VideoChatScheduled Parse(const Value& value, To<VideoChatScheduled>);

}  // namespace tg
