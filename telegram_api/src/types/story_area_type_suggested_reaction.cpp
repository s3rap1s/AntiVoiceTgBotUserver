#include <tg/types/reaction_type.hpp>
#include <tg/types/story_area_type_suggested_reaction.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

StoryAreaTypeSuggestedReaction Parse(const Value& value, To<StoryAreaTypeSuggestedReaction>) {
    StoryAreaTypeSuggestedReaction obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.reaction_type = ParseComplex<ReactionType>(value["reaction_type"]);
    obj.is_dark = ParseComplex<Optional<Boolean>>(value["is_dark"]);
    obj.is_flipped = ParseComplex<Optional<Boolean>>(value["is_flipped"]);
    return obj;
}

void Serialize(const StoryAreaTypeSuggestedReaction& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "reaction_type", obj.reaction_type);
    internal::Put(builder, "is_dark", obj.is_dark);
    internal::Put(builder, "is_flipped", obj.is_flipped);
}

}  // namespace tg
