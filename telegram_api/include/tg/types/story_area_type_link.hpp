#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct StoryAreaTypeLink {
    String type;
    String url;
};

StoryAreaTypeLink Parse(const Value& value, To<StoryAreaTypeLink>);

}  // namespace tg
