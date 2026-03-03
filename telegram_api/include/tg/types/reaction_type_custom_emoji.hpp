#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct ReactionTypeCustomEmoji {
    String type;
    String custom_emoji_id;
};

ReactionTypeCustomEmoji Parse(const Value& value, To<ReactionTypeCustomEmoji>);

void Serialize(const ReactionTypeCustomEmoji& obj, ValueBuilder& builder);

}  // namespace tg
