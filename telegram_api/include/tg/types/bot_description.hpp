#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct BotDescription {
    String description;
};

BotDescription Parse(const Value& value, To<BotDescription>);

void Serialize(const BotDescription& obj, ValueBuilder& builder);

}  // namespace tg
