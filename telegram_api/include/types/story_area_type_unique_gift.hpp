#pragma once

#include "common.hpp"

namespace tg {

struct StoryAreaTypeUniqueGift {
    String type;
    Integer name;
};

StoryAreaTypeUniqueGift Parse(const Value& value, To<StoryAreaTypeUniqueGift>);

}  // namespace tg
