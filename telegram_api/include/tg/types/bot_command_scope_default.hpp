#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct BotCommandScopeDefault {
    String type;
};

BotCommandScopeDefault Parse(const Value& value, To<BotCommandScopeDefault>);

}  // namespace tg
