#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct BotCommandScopeAllGroupChats {
    String type;
};

BotCommandScopeAllGroupChats Parse(const Value& value, To<BotCommandScopeAllGroupChats>);

void Serialize(const BotCommandScopeAllGroupChats& obj, ValueBuilder& builder);

}  // namespace tg
