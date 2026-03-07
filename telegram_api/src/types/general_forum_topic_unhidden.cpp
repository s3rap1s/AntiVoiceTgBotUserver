#include <tg/types/general_forum_topic_unhidden.hpp>

#include "common.hpp"

namespace tg {

GeneralForumTopicUnhidden Parse(const Value& value, To<GeneralForumTopicUnhidden>) {
    (void)value;
    return GeneralForumTopicUnhidden{};
}

void Serialize(const GeneralForumTopicUnhidden& obj, ValueBuilder& builder) {
    (void)obj;
    (void)builder;
}

}  // namespace tg
