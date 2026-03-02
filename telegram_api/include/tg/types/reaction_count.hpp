#pragma once

#include <tg/types/common.hpp>
#include <tg/types/reaction_type.hpp>

namespace tg {

struct ReactionCount {
    ReactionType type;
    Integer total_count;
};

ReactionCount Parse(const Value& value, To<ReactionCount>);

}  // namespace tg
