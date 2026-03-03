#pragma once

#include <userver/formats/json/value_builder.hpp>

#include "story_area_position.hpp"
#include "story_area_type.hpp"

namespace tg {

using ValueBuilder = userver::formats::json::ValueBuilder;

struct StoryArea {
    StoryAreaPosition position;
    StoryAreaType type;
};

StoryArea Parse(const Value& value, To<StoryArea>);

void Serialize(const StoryArea& obj, ValueBuilder& builder);

}  // namespace tg
