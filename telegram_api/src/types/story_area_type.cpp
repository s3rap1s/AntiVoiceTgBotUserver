#include <tg/types/story_area_type.hpp>
#include <tg/types/story_area_type_link.hpp>
#include <tg/types/story_area_type_location.hpp>
#include <tg/types/story_area_type_suggested_reaction.hpp>
#include <tg/types/story_area_type_unique_gift.hpp>
#include <tg/types/story_area_type_weather.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

StoryAreaType Parse(const Value& value, To<StoryAreaType>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "location") return ParseComplex<StoryAreaTypeLocation>(value);
    if (type == "suggested_reaction") return ParseComplex<StoryAreaTypeSuggestedReaction>(value);
    if (type == "link") return ParseComplex<StoryAreaTypeLink>(value);
    if (type == "weather") return ParseComplex<StoryAreaTypeWeather>(value);
    if (type == "unique_gift") return ParseComplex<StoryAreaTypeUniqueGift>(value);
    throw ParseException("Unknown StoryAreaType type: " + type);
}

void Serialize(const StoryAreaType& obj, ValueBuilder& builder) { internal::Set(builder, obj); }

}  // namespace tg
