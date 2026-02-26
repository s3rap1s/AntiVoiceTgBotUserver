#pragma once

#include "common.hpp"
#include "reaction_type.hpp"

namespace tg {

struct StoryAreaTypeSuggestedReaction {
    String type;
    ReactionType reaction;
    Optional<Boolean> is_dark;
    Optional<Boolean> is_flipped;
};

StoryAreaTypeSuggestedReaction Parse(const Value& value,
                                     To<StoryAreaTypeSuggestedReaction>);

}  // namespace tg
