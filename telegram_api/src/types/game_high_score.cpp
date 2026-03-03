#include <tg/types/game_high_score.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

GameHighScore Parse(const Value& value, To<GameHighScore>) {
    GameHighScore obj{};
    obj.position = ParseComplex<Integer>(value["position"]);
    obj.user = ParseComplex<User>(value["user"]);
    obj.score = ParseComplex<Integer>(value["score"]);
    return obj;
}

void Serialize(const GameHighScore& obj, ValueBuilder& builder) {
    internal::Put(builder, "position", obj.position);
    internal::Put(builder, "user", obj.user);
    internal::Put(builder, "score", obj.score);
}

}  // namespace tg
