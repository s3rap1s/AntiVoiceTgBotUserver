#pragma once

#include <types/common.hpp>

namespace tg {

struct BotCommandScopeChatMember {
    String type;
    OneOf<Integer, String> chat_id;
    Integer user_id;
};

BotCommandScopeChatMember Parse(const Value& value,
                                To<BotCommandScopeChatMember>);

}  // namespace tg
