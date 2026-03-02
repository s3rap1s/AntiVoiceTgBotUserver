#pragma once

#include "story_area_type_link.hpp"
#include "story_area_type_location.hpp"
#include "story_area_type_suggested_reaction.hpp"
#include "story_area_type_unique_gift.hpp"
#include "story_area_type_weather.hpp"

namespace tg {

using StoryAreaType =
    OneOf<StoryAreaTypeLocation, StoryAreaTypeSuggestedReaction,
          StoryAreaTypeLink, StoryAreaTypeWeather, StoryAreaTypeUniqueGift>;

StoryAreaType Parse(const Value& value, To<StoryAreaType>);

}  // namespace tg
