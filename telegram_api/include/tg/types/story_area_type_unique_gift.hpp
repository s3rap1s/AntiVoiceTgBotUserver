#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct StoryAreaTypeUniqueGift {
    String type;
    String name;
};

StoryAreaTypeUniqueGift Parse(const Value& value, To<StoryAreaTypeUniqueGift>);

void Serialize(const StoryAreaTypeUniqueGift& obj, ValueBuilder& builder);

}  // namespace tg
