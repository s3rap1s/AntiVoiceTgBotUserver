#include <tg/types/forum_topic_closed.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ForumTopicClosed Parse(const Value& value, To<ForumTopicClosed>) {
    (void)value;
    return ForumTopicClosed{};
}

void Serialize(const ForumTopicClosed& obj, ValueBuilder& builder) {
    (void)obj;
    (void)builder;
}

}  // namespace tg
