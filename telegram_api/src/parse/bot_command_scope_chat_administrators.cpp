#include <tg/types/bot_command_scope_chat_administrators.hpp>

#include "common.hpp"

namespace tg {

BotCommandScopeChatAdministrators Parse(const Value& value,
                                        To<BotCommandScopeChatAdministrators>) {
    BotCommandScopeChatAdministrators obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.chat_id = ParseComplex<OneOf<Integer, String>>(value["chat_id"]);
    return obj;
}

}  // namespace tg
