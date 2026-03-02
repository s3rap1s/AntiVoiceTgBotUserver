#include <tg/types/reaction_type_emoji.hpp>

#include "common.hpp"

namespace tg {

ReactionTypeEmoji Parse(const Value& value, To<ReactionTypeEmoji>) {
    ReactionTypeEmoji obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.emoji = ParseComplex<String>(value["emoji"]);
    return obj;
}

}  // namespace tg
