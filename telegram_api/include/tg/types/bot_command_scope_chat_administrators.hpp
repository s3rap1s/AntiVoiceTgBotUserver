#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct BotCommandScopeChatAdministrators {
    String type;
    OneOf<Integer, String> chat_id;
};

BotCommandScopeChatAdministrators Parse(const Value& value, To<BotCommandScopeChatAdministrators>);

void Serialize(const BotCommandScopeChatAdministrators& obj, ValueBuilder& builder);

}  // namespace tg
