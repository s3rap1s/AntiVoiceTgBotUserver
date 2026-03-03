#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct BotCommandScopeAllChatAdministrators {
    String type;
};

BotCommandScopeAllChatAdministrators Parse(const Value& value, To<BotCommandScopeAllChatAdministrators>);

void Serialize(const BotCommandScopeAllChatAdministrators& obj, ValueBuilder& builder);

}  // namespace tg
