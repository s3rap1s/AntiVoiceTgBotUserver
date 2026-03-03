#include <tg/types/bot_command_scope_chat.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BotCommandScopeChat Parse(const Value& value, To<BotCommandScopeChat>) {
    BotCommandScopeChat obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.chat_id = ParseComplex<OneOf<Integer, String>>(value["chat_id"]);
    return obj;
}

void Serialize(const BotCommandScopeChat& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "chat_id", obj.chat_id);
}

}  // namespace tg
