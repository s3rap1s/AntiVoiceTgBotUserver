#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct BotCommandScopeDefault {
    String type;
};

BotCommandScopeDefault Parse(const Value& value, To<BotCommandScopeDefault>);

void Serialize(const BotCommandScopeDefault& obj, ValueBuilder& builder);

}  // namespace tg
