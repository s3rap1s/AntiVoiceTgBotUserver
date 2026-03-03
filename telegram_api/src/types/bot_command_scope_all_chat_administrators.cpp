#include <tg/types/bot_command_scope_all_chat_administrators.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BotCommandScopeAllChatAdministrators Parse(const Value& value, To<BotCommandScopeAllChatAdministrators>) {
    BotCommandScopeAllChatAdministrators obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

void Serialize(const BotCommandScopeAllChatAdministrators& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
}

}  // namespace tg
