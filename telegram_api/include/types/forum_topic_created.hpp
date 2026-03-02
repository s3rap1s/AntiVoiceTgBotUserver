#pragma once

#include <types/common.hpp>

namespace tg {

struct ForumTopicCreated {
    String name;
    Integer icon_color;
    Optional<String> icon_custom_emoji_id;
    OptionalTrue is_name_implicit;
};

ForumTopicCreated Parse(const Value& value, To<ForumTopicCreated>);

}  // namespace tg
