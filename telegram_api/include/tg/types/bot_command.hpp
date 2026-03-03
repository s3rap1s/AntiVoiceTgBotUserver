#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct BotCommand {
    String command;
    String description;
};

BotCommand Parse(const Value& value, To<BotCommand>);

void Serialize(const BotCommand& obj, ValueBuilder& builder);

}  // namespace tg
