#pragma once

#include "chat.hpp"
#include "common.hpp"
#include "reaction_count.hpp"

namespace tg {

struct MessageReactionCountUpdated {
    Chat chat;
    Integer message_id;
    Integer date;
    Array<ReactionCount> reactions;
};

MessageReactionCountUpdated Parse(const Value& value,
                                  To<MessageReactionCountUpdated>);

}  // namespace tg
