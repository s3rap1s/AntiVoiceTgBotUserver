#include <tg/types/forum_topic.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ForumTopic Parse(const Value& value, To<ForumTopic>) {
    ForumTopic obj{};
    obj.message_thread_id = ParseComplex<Integer>(value["message_thread_id"]);
    obj.name = ParseComplex<String>(value["name"]);
    obj.icon_color = ParseComplex<Integer>(value["icon_color"]);
    obj.icon_custom_emoji_id = ParseComplex<Optional<String>>(value["icon_custom_emoji_id"]);
    obj.is_name_implicit = ParseComplex<OptionalTrue>(value["is_name_implicit"]);
    return obj;
}

void Serialize(const ForumTopic& obj, ValueBuilder& builder) {
    internal::Put(builder, "message_thread_id", obj.message_thread_id);
    internal::Put(builder, "name", obj.name);
    internal::Put(builder, "icon_color", obj.icon_color);
    internal::Put(builder, "icon_custom_emoji_id", obj.icon_custom_emoji_id);
    internal::Put(builder, "is_name_implicit", obj.is_name_implicit);
}

}  // namespace tg
