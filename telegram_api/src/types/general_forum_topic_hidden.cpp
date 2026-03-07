#include <tg/types/general_forum_topic_hidden.hpp>

#include "common.hpp"

namespace tg {

GeneralForumTopicHidden Parse(const Value& value, To<GeneralForumTopicHidden>) {
    (void)value;
    return GeneralForumTopicHidden{};
}

void Serialize(const GeneralForumTopicHidden& obj, ValueBuilder& builder) {
    (void)obj;
    (void)builder;
}

}  // namespace tg
