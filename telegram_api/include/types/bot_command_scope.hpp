#pragma once

#include "bot_command_scope_all_chat_administrators.hpp"
#include "bot_command_scope_all_group_chats.hpp"
#include "bot_command_scope_all_private_chats.hpp"
#include "bot_command_scope_chat.hpp"
#include "bot_command_scope_chat_administrators.hpp"
#include "bot_command_scope_chat_member.hpp"
#include "bot_command_scope_default.hpp"
#include "common.hpp"

namespace tg {

using BotCommandScope =
    OneOf<BotCommandScopeDefault, BotCommandScopeAllPrivateChats,
          BotCommandScopeAllGroupChats, BotCommandScopeAllChatAdministrators,
          BotCommandScopeChat, BotCommandScopeChatAdministrators,
          BotCommandScopeChatMember>;

BotCommandScope Parse(const Value& value, To<BotCommandScope>);

}  // namespace tg
