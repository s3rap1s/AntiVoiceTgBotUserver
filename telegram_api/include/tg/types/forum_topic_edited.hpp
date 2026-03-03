#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct ForumTopicEdited {
    Optional<String> name;
    Optional<String> icon_custom_emoji_id;
};

ForumTopicEdited Parse(const Value& value, To<ForumTopicEdited>);

void Serialize(const ForumTopicEdited& obj, ValueBuilder& builder);

}  // namespace tg
