#include <types/bot_command_scope.hpp>
#include <types/bot_command_scope_all_chat_administrators.hpp>
#include <types/bot_command_scope_all_group_chats.hpp>
#include <types/bot_command_scope_all_private_chats.hpp>
#include <types/bot_command_scope_chat.hpp>
#include <types/bot_command_scope_chat_administrators.hpp>
#include <types/bot_command_scope_chat_member.hpp>
#include <types/bot_command_scope_default.hpp>

#include "common.hpp"

namespace tg {

BotCommandScope Parse(const Value& value, To<BotCommandScope>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "default") return ParseComplex<BotCommandScopeDefault>(value);
    if (type == "all_private_chats")
        return ParseComplex<BotCommandScopeAllPrivateChats>(value);
    if (type == "all_group_chats")
        return ParseComplex<BotCommandScopeAllGroupChats>(value);
    if (type == "all_chat_administrators")
        return ParseComplex<BotCommandScopeAllChatAdministrators>(value);
    if (type == "chat") return ParseComplex<BotCommandScopeChat>(value);
    if (type == "chat_administrators")
        return ParseComplex<BotCommandScopeChatAdministrators>(value);
    if (type == "chat_member")
        return ParseComplex<BotCommandScopeChatMember>(value);
    throw std::runtime_error("Unknown BotCommandScope type: " + type);
}

}  // namespace tg
