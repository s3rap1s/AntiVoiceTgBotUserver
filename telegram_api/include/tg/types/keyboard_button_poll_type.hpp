#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct KeyboardButtonPollType {
    Optional<String> type;
};

KeyboardButtonPollType Parse(const Value& value, To<KeyboardButtonPollType>);

}  // namespace tg
