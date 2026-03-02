#include <types/general_forum_topic_hidden.hpp>

#include "common.hpp"

namespace tg {

GeneralForumTopicHidden Parse(const Value& value, To<GeneralForumTopicHidden>) {
    (void)value;
    return GeneralForumTopicHidden{};
}

}  // namespace tg
