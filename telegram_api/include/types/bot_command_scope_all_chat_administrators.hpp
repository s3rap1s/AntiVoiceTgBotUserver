#pragma once

#include "common.hpp"

namespace tg {

struct BotCommandScopeAllChatAdministrators {
    String type;
};

BotCommandScopeAllChatAdministrators Parse(
    const Value& value, To<BotCommandScopeAllChatAdministrators>);

}  // namespace tg
