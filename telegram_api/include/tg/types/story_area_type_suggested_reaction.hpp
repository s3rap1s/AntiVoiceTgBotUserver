#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include "reaction_type.hpp"

namespace tg {

struct StoryAreaTypeSuggestedReaction {
    String type;
    ReactionType reaction_type;
    Optional<Boolean> is_dark;
    Optional<Boolean> is_flipped;
};

StoryAreaTypeSuggestedReaction Parse(const Value& value, To<StoryAreaTypeSuggestedReaction>);

void Serialize(const StoryAreaTypeSuggestedReaction& obj, ValueBuilder& builder);

}  // namespace tg
