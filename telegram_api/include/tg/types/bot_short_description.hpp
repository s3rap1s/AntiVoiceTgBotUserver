#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct BotShortDescription {
    String short_description;
};

BotShortDescription Parse(const Value& value, To<BotShortDescription>);

void Serialize(const BotShortDescription& obj, ValueBuilder& builder);

}  // namespace tg
