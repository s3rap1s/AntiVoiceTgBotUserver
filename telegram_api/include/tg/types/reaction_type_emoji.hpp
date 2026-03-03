#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct ReactionTypeEmoji {
    String type;
    String emoji;
};

ReactionTypeEmoji Parse(const Value& value, To<ReactionTypeEmoji>);

void Serialize(const ReactionTypeEmoji& obj, ValueBuilder& builder);

}  // namespace tg
