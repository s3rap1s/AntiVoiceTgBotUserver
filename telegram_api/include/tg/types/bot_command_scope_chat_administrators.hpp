#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct BotCommandScopeChatAdministrators {
    String type;
    OneOf<Integer, String> chat_id;
};

BotCommandScopeChatAdministrators Parse(const Value& value,
                                        To<BotCommandScopeChatAdministrators>);

}  // namespace tg
