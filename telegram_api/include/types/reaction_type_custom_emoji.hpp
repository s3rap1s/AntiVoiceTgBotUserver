#pragma once

#include "common.hpp"

namespace tg {

struct ReactionTypeCustomEmoji {
    String type;
    String custom_emoji_id;
};

ReactionTypeCustomEmoji Parse(const Value& value, To<ReactionTypeCustomEmoji>);

}  // namespace tg
