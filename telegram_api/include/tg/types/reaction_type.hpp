#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/reaction_type_custom_emoji.hpp>
#include <tg/types/reaction_type_emoji.hpp>
#include <tg/types/reaction_type_paid.hpp>

namespace tg {

using ReactionType = OneOf<ReactionTypeEmoji, ReactionTypeCustomEmoji, ReactionTypePaid>;

ReactionType Parse(const Value& value, To<ReactionType>);

void Serialize(const ReactionType& obj, ValueBuilder& builder);

}  // namespace tg
