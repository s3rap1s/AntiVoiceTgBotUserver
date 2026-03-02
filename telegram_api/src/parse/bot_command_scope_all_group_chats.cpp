#include <types/bot_command_scope_all_group_chats.hpp>

#include "common.hpp"

namespace tg {

BotCommandScopeAllGroupChats Parse(const Value& value,
                                   To<BotCommandScopeAllGroupChats>) {
    BotCommandScopeAllGroupChats obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

}  // namespace tg
