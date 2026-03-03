#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct UserRating {
    Integer level;
    Integer rating;
    Integer current_level_rating;
    Optional<Integer> next_level_rating;
};

UserRating Parse(const Value& value, To<UserRating>);

void Serialize(const UserRating& obj, ValueBuilder& builder);

}  // namespace tg
