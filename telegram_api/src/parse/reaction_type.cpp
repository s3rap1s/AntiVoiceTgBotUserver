#include <types/reaction_type.hpp>
#include <types/reaction_type_custom_emoji.hpp>
#include <types/reaction_type_emoji.hpp>
#include <types/reaction_type_paid.hpp>

#include "common.hpp"

namespace tg {

ReactionType Parse(const Value& value, To<ReactionType>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "emoji") return ParseComplex<ReactionTypeEmoji>(value);
    if (type == "custom_emoji")
        return ParseComplex<ReactionTypeCustomEmoji>(value);
    if (type == "paid") return ParseComplex<ReactionTypePaid>(value);
    throw std::runtime_error("Unknown ReactionType type: " + type);
}

}  // namespace tg
