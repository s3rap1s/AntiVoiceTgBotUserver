#pragma once

#include <types/common.hpp>

namespace tg {

struct BotCommandScopeAllGroupChats {
    String type;
};

BotCommandScopeAllGroupChats Parse(const Value& value,
                                   To<BotCommandScopeAllGroupChats>);

}  // namespace tg
