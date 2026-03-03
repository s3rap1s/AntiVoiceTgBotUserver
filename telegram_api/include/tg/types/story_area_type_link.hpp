#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct StoryAreaTypeLink {
    String type;
    String url;
};

StoryAreaTypeLink Parse(const Value& value, To<StoryAreaTypeLink>);

void Serialize(const StoryAreaTypeLink& obj, ValueBuilder& builder);

}  // namespace tg
