#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct ReplyKeyboardRemove {
    OptionalTrue remove_keyboard;
    Optional<Boolean> selective;
};

ReplyKeyboardRemove Parse(const Value& value, To<ReplyKeyboardRemove>);

}  // namespace tg
