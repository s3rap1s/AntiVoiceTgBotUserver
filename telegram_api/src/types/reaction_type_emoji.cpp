#include <tg/types/reaction_type_emoji.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ReactionTypeEmoji Parse(const Value& value, To<ReactionTypeEmoji>) {
    ReactionTypeEmoji obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.emoji = ParseComplex<String>(value["emoji"]);
    return obj;
}

void Serialize(const ReactionTypeEmoji& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "emoji", obj.emoji);
}

}  // namespace tg
