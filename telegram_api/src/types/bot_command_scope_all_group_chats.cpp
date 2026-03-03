#include <tg/types/bot_command_scope_all_group_chats.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BotCommandScopeAllGroupChats Parse(const Value& value, To<BotCommandScopeAllGroupChats>) {
    BotCommandScopeAllGroupChats obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

void Serialize(const BotCommandScopeAllGroupChats& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
}

}  // namespace tg
