#include <tg/types/bot_command_scope_default.hpp>

#include "common.hpp"

namespace tg {

BotCommandScopeDefault Parse(const Value& value, To<BotCommandScopeDefault>) {
    BotCommandScopeDefault obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

}  // namespace tg
