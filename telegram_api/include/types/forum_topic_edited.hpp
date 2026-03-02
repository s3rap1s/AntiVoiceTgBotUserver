#pragma once

#include <types/common.hpp>

namespace tg {

struct ForumTopicEdited {
    Optional<String> name;
    Optional<String> icon_custom_emoji_id;
};

ForumTopicEdited Parse(const Value& value, To<ForumTopicEdited>);

}  // namespace tg
