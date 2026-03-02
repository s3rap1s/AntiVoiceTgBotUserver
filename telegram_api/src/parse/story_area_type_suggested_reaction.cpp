#include <tg/types/reaction_type.hpp>
#include <tg/types/story_area_type_suggested_reaction.hpp>

#include "common.hpp"

namespace tg {

StoryAreaTypeSuggestedReaction Parse(const Value& value,
                                     To<StoryAreaTypeSuggestedReaction>) {
    StoryAreaTypeSuggestedReaction obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.reaction_type = ParseComplex<ReactionType>(value["reaction_type"]);
    obj.is_dark = ParseComplex<Optional<Boolean>>(value["is_dark"]);
    obj.is_flipped = ParseComplex<Optional<Boolean>>(value["is_flipped"]);
    return obj;
}

}  // namespace tg
