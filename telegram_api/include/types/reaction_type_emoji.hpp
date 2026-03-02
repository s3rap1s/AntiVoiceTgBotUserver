#pragma once

#include <types/common.hpp>

namespace tg {

struct ReactionTypeEmoji {
    String type;
    String emoji;
};

ReactionTypeEmoji Parse(const Value& value, To<ReactionTypeEmoji>);

}  // namespace tg
