#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct GameHighScore {
    Integer position;
    User user;
    Integer score;
};

GameHighScore Parse(const Value& value, To<GameHighScore>);

void Serialize(const GameHighScore& obj, ValueBuilder& builder);

}  // namespace tg
