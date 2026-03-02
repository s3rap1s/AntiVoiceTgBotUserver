#pragma once

#include <tg/types/common.hpp>
#include <tg/types/reaction_type_custom_emoji.hpp>
#include <tg/types/reaction_type_emoji.hpp>
#include <tg/types/reaction_type_paid.hpp>

namespace tg {

using ReactionType =
    OneOf<ReactionTypeEmoji, ReactionTypeCustomEmoji, ReactionTypePaid>;

ReactionType Parse(const Value& value, To<ReactionType>);

}  // namespace tg
