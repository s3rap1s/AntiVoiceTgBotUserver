#include <tg/types/bot_command_scope_all_private_chats.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BotCommandScopeAllPrivateChats Parse(const Value& value, To<BotCommandScopeAllPrivateChats>) {
    BotCommandScopeAllPrivateChats obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

void Serialize(const BotCommandScopeAllPrivateChats& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
}

}  // namespace tg
