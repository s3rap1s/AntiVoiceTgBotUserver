#include <tg/types/reaction_type_custom_emoji.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ReactionTypeCustomEmoji Parse(const Value& value, To<ReactionTypeCustomEmoji>) {
    ReactionTypeCustomEmoji obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.custom_emoji_id = ParseComplex<String>(value["custom_emoji_id"]);
    return obj;
}

void Serialize(const ReactionTypeCustomEmoji& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "custom_emoji_id", obj.custom_emoji_id);
}

}  // namespace tg
