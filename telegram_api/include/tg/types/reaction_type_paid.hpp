#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct ReactionTypePaid {
    String type;
};

ReactionTypePaid Parse(const Value& value, To<ReactionTypePaid>);

}  // namespace tg
