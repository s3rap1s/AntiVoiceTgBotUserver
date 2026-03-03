#include <tg/types/reaction_type.hpp>
#include <tg/types/reaction_type_custom_emoji.hpp>
#include <tg/types/reaction_type_emoji.hpp>
#include <tg/types/reaction_type_paid.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ReactionType Parse(const Value& value, To<ReactionType>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "emoji") return ParseComplex<ReactionTypeEmoji>(value);
    if (type == "custom_emoji") return ParseComplex<ReactionTypeCustomEmoji>(value);
    if (type == "paid") return ParseComplex<ReactionTypePaid>(value);
    throw ParseException("Unknown ReactionType type: " + type);
}

void Serialize(const ReactionType& obj, ValueBuilder& builder) { internal::Set(builder, obj); }

}  // namespace tg
