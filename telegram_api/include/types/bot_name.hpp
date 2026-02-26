#pragma once

#include "common.hpp"

namespace tg {

struct BotName {
    String name;
};

BotName Parse(const Value& value, To<BotName>);

}  // namespace tg
