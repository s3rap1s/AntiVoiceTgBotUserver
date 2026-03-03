#include <tg/types/bot_command_scope_chat_administrators.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BotCommandScopeChatAdministrators Parse(const Value& value, To<BotCommandScopeChatAdministrators>) {
    BotCommandScopeChatAdministrators obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.chat_id = ParseComplex<OneOf<Integer, String>>(value["chat_id"]);
    return obj;
}

void Serialize(const BotCommandScopeChatAdministrators& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "chat_id", obj.chat_id);
}

}  // namespace tg
