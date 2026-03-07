#include <tg/types/forum_topic_reopened.hpp>

#include "common.hpp"

namespace tg {

ForumTopicReopened Parse(const Value& value, To<ForumTopicReopened>) {
    (void)value;
    return ForumTopicReopened{};
}

void Serialize(const ForumTopicReopened& obj, ValueBuilder& builder) {
    (void)obj;
    (void)builder;
}

}  // namespace tg
