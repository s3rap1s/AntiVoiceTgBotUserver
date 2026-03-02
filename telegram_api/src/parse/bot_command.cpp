#include <tg/types/bot_command.hpp>

#include "common.hpp"

namespace tg {

BotCommand Parse(const Value& value, To<BotCommand>) {
    BotCommand obj{};
    obj.command = ParseComplex<String>(value["command"]);
    obj.description = ParseComplex<String>(value["description"]);
    return obj;
}

}  // namespace tg
