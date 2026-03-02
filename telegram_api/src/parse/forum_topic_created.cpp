#include <tg/types/forum_topic_created.hpp>

#include "common.hpp"

namespace tg {

ForumTopicCreated Parse(const Value& value, To<ForumTopicCreated>) {
    ForumTopicCreated obj{};
    obj.name = ParseComplex<String>(value["name"]);
    obj.icon_color = ParseComplex<Integer>(value["icon_color"]);
    obj.icon_custom_emoji_id =
        ParseComplex<Optional<String>>(value["icon_custom_emoji_id"]);
    obj.is_name_implicit =
        ParseComplex<OptionalTrue>(value["is_name_implicit"]);
    return obj;
}

}  // namespace tg
