#pragma once

#include "story_area_position.hpp"
#include "story_area_type.hpp"

namespace tg {

struct StoryArea {
    StoryAreaPosition position;
    StoryAreaType type;
};

StoryArea Parse(const Value& value, To<StoryArea>);

}  // namespace tg
