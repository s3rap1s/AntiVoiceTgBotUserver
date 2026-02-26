#pragma once

#include "common.hpp"

namespace tg {

struct UserRating {
    Integer level;
    Integer rating;
    Integer current_level_rating;
    Optional<Integer> next_level_rating;
};

UserRating Parse(const Value& value, To<UserRating>);

}  // namespace tg
