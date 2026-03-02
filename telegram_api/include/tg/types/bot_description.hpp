#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct BotDescription {
    String description;
};

BotDescription Parse(const Value& value, To<BotDescription>);

}  // namespace tg
