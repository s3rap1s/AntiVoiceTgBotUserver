#include <types/reaction_type_custom_emoji.hpp>

#include "common.hpp"

namespace tg {

ReactionTypeCustomEmoji Parse(const Value& value, To<ReactionTypeCustomEmoji>) {
    ReactionTypeCustomEmoji obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.custom_emoji_id = ParseComplex<String>(value["custom_emoji_id"]);
    return obj;
}

}  // namespace tg
