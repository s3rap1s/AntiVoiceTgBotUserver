#pragma once

#include "common.hpp"

namespace tg {

struct BotShortDescription {
    String short_description;
};

BotShortDescription Parse(const Value& value, To<BotShortDescription>);

}  // namespace tg
