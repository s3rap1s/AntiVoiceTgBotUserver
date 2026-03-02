#include <types/game_high_score.hpp>
#include <types/user.hpp>

#include "common.hpp"

namespace tg {

GameHighScore Parse(const Value& value, To<GameHighScore>) {
    GameHighScore obj{};
    obj.position = ParseComplex<Integer>(value["position"]);
    obj.user = ParseComplex<User>(value["user"]);
    obj.score = ParseComplex<Integer>(value["score"]);
    return obj;
}

}  // namespace tg
