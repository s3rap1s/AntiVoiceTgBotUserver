#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct BotName {
    String name;
};

BotName Parse(const Value& value, To<BotName>);

void Serialize(const BotName& obj, ValueBuilder& builder);

}  // namespace tg
