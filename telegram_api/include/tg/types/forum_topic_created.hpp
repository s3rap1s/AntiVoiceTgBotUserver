#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct ForumTopicCreated {
    String name;
    Integer icon_color;
    Optional<String> icon_custom_emoji_id;
    OptionalTrue is_name_implicit;
};

ForumTopicCreated Parse(const Value& value, To<ForumTopicCreated>);

void Serialize(const ForumTopicCreated& obj, ValueBuilder& builder);

}  // namespace tg
