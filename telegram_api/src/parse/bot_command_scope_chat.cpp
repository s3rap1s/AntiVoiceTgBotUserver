#include <tg/types/bot_command_scope_chat.hpp>

#include "common.hpp"

namespace tg {

BotCommandScopeChat Parse(const Value& value, To<BotCommandScopeChat>) {
    BotCommandScopeChat obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.chat_id = ParseComplex<OneOf<Integer, String>>(value["chat_id"]);
    return obj;
}

}  // namespace tg
