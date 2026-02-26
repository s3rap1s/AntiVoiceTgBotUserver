#pragma once

#include "common.hpp"

namespace tg {

struct KeyboardButtonPollType {
    Optional<String> type;
};

KeyboardButtonPollType Parse(const Value& value, To<KeyboardButtonPollType>);

}  // namespace tg
