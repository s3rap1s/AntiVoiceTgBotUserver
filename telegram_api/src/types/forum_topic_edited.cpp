#include <tg/types/forum_topic_edited.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ForumTopicEdited Parse(const Value& value, To<ForumTopicEdited>) {
    ForumTopicEdited obj{};
    obj.name = ParseComplex<Optional<String>>(value["name"]);
    obj.icon_custom_emoji_id = ParseComplex<Optional<String>>(value["icon_custom_emoji_id"]);
    return obj;
}

void Serialize(const ForumTopicEdited& obj, ValueBuilder& builder) {
    internal::Put(builder, "name", obj.name);
    internal::Put(builder, "icon_custom_emoji_id", obj.icon_custom_emoji_id);
}

}  // namespace tg
