#include <tg/types/bot_command_scope_chat_member.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BotCommandScopeChatMember Parse(const Value& value, To<BotCommandScopeChatMember>) {
    BotCommandScopeChatMember obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.chat_id = ParseComplex<OneOf<Integer, String>>(value["chat_id"]);
    obj.user_id = ParseComplex<Integer>(value["user_id"]);
    return obj;
}

void Serialize(const BotCommandScopeChatMember& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "chat_id", obj.chat_id);
    internal::Put(builder, "user_id", obj.user_id);
}

}  // namespace tg
