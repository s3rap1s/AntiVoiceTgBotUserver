#pragma once

#include "background_type.hpp"

namespace tg {

struct ChatBackground {
    BackgroundType type;
};

ChatBackground Parse(const Value& value, To<ChatBackground>);

}  // namespace tg
