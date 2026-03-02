#include <types/forum_topic_closed.hpp>

#include "common.hpp"

namespace tg {

ForumTopicClosed Parse(const Value& value, To<ForumTopicClosed>) {
    (void)value;
    return ForumTopicClosed{};
}

}  // namespace tg
