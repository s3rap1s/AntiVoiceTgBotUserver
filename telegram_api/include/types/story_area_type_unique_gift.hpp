#pragma once

#include <types/common.hpp>

namespace tg {

struct StoryAreaTypeUniqueGift {
    String type;
    String name;
};

StoryAreaTypeUniqueGift Parse(const Value& value, To<StoryAreaTypeUniqueGift>);

}  // namespace tg
