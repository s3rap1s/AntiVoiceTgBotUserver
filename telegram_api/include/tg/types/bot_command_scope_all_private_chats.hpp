#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct BotCommandScopeAllPrivateChats {
    String type;
};

BotCommandScopeAllPrivateChats Parse(const Value& value, To<BotCommandScopeAllPrivateChats>);

void Serialize(const BotCommandScopeAllPrivateChats& obj, ValueBuilder& builder);

}  // namespace tg
