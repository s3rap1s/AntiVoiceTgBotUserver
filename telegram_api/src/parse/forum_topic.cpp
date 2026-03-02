#include <types/forum_topic.hpp>

#include "common.hpp"

namespace tg {

ForumTopic Parse(const Value& value, To<ForumTopic>) {
    ForumTopic obj{};
    obj.message_thread_id = ParseComplex<Integer>(value["message_thread_id"]);
    obj.name = ParseComplex<String>(value["name"]);
    obj.icon_color = ParseComplex<Integer>(value["icon_color"]);
    obj.icon_custom_emoji_id =
        ParseComplex<Optional<String>>(value["icon_custom_emoji_id"]);
    obj.is_name_implicit =
        ParseComplex<OptionalTrue>(value["is_name_implicit"]);
    return obj;
}

}  // namespace tg
