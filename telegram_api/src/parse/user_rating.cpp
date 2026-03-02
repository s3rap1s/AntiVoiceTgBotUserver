#include <types/user_rating.hpp>

#include "common.hpp"

namespace tg {

UserRating Parse(const Value& value, To<UserRating>) {
    UserRating obj{};
    obj.level = ParseComplex<Integer>(value["level"]);
    obj.rating = ParseComplex<Integer>(value["rating"]);
    obj.current_level_rating =
        ParseComplex<Integer>(value["current_level_rating"]);
    obj.next_level_rating =
        ParseComplex<Optional<Integer>>(value["next_level_rating"]);
    return obj;
}

}  // namespace tg
