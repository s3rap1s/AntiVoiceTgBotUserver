#pragma once

#include <types/common.hpp>
#include <types/user.hpp>

namespace tg {

struct GameHighScore {
    Integer position;
    User user;
    Integer score;
};

GameHighScore Parse(const Value& value, To<GameHighScore>);

}  // namespace tg
