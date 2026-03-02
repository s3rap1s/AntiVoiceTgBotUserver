#pragma once

#include <types/common.hpp>
#include <types/reaction_type_custom_emoji.hpp>
#include <types/reaction_type_emoji.hpp>
#include <types/reaction_type_paid.hpp>

namespace tg {

using ReactionType =
    OneOf<ReactionTypeEmoji, ReactionTypeCustomEmoji, ReactionTypePaid>;

ReactionType Parse(const Value& value, To<ReactionType>);

}  // namespace tg
