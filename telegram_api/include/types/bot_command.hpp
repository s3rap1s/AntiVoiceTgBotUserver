#pragma once

#include "common.hpp"

namespace tg {

struct BotCommand {
    String command;
    String description;
};

BotCommand Parse(const Value& value, To<BotCommand>);

}  // namespace tg
