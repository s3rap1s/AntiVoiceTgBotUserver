#pragma once

#include "common.hpp"

namespace tg {

struct BotCommandScopeAllPrivateChats {
    String type;
};

BotCommandScopeAllPrivateChats Parse(const Value& value,
                                     To<BotCommandScopeAllPrivateChats>);

}  // namespace tg
