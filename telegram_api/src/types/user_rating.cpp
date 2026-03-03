#include <tg/types/user_rating.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

UserRating Parse(const Value& value, To<UserRating>) {
    UserRating obj{};
    obj.level = ParseComplex<Integer>(value["level"]);
    obj.rating = ParseComplex<Integer>(value["rating"]);
    obj.current_level_rating = ParseComplex<Integer>(value["current_level_rating"]);
    obj.next_level_rating = ParseComplex<Optional<Integer>>(value["next_level_rating"]);
    return obj;
}

void Serialize(const UserRating& obj, ValueBuilder& builder) {
    internal::Put(builder, "level", obj.level);
    internal::Put(builder, "rating", obj.rating);
    internal::Put(builder, "current_level_rating", obj.current_level_rating);
    internal::Put(builder, "next_level_rating", obj.next_level_rating);
}

}  // namespace tg
