#include <types/story_area_type.hpp>
#include <types/story_area_type_link.hpp>
#include <types/story_area_type_location.hpp>
#include <types/story_area_type_suggested_reaction.hpp>
#include <types/story_area_type_unique_gift.hpp>
#include <types/story_area_type_weather.hpp>

#include "common.hpp"

namespace tg {

StoryAreaType Parse(const Value& value, To<StoryAreaType>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "location") return ParseComplex<StoryAreaTypeLocation>(value);
    if (type == "suggested_reaction")
        return ParseComplex<StoryAreaTypeSuggestedReaction>(value);
    if (type == "link") return ParseComplex<StoryAreaTypeLink>(value);
    if (type == "weather") return ParseComplex<StoryAreaTypeWeather>(value);
    if (type == "unique_gift")
        return ParseComplex<StoryAreaTypeUniqueGift>(value);
    throw std::runtime_error("Unknown StoryAreaType type: " + type);
}

}  // namespace tg
