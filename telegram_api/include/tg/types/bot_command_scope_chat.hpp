#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct BotCommandScopeChat {
    String type;
    OneOf<Integer, String> chat_id;
};

BotCommandScopeChat Parse(const Value& value, To<BotCommandScopeChat>);

void Serialize(const BotCommandScopeChat& obj, ValueBuilder& builder);

}  // namespace tg
