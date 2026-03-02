#include <tg/types/bot_command_scope_chat_member.hpp>

#include "common.hpp"

namespace tg {

BotCommandScopeChatMember Parse(const Value& value,
                                To<BotCommandScopeChatMember>) {
    BotCommandScopeChatMember obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.chat_id = ParseComplex<OneOf<Integer, String>>(value["chat_id"]);
    obj.user_id = ParseComplex<Integer>(value["user_id"]);
    return obj;
}

}  // namespace tg
