#include <tg/types/bot_command_scope_all_private_chats.hpp>

#include "common.hpp"

namespace tg {

BotCommandScopeAllPrivateChats Parse(const Value& value,
                                     To<BotCommandScopeAllPrivateChats>) {
    BotCommandScopeAllPrivateChats obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

}  // namespace tg
