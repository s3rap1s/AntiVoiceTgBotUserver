#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct ForumTopic {
    Integer message_thread_id;
    String name;
    Integer icon_color;
    Optional<String> icon_custom_emoji_id;
    OptionalTrue is_name_implicit;
};

ForumTopic Parse(const Value& value, To<ForumTopic>);

void Serialize(const ForumTopic& obj, ValueBuilder& builder);

}  // namespace tg
