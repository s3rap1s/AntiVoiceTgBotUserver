#include <tg/types/forum_topic_reopened.hpp>

#include "common.hpp"

namespace tg {

ForumTopicReopened Parse(const Value& value, To<ForumTopicReopened>) {
    (void)value;
    return ForumTopicReopened{};
}

}  // namespace tg
