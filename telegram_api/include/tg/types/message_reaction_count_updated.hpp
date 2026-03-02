#pragma once

#include <tg/types/chat.hpp>
#include <tg/types/common.hpp>
#include <tg/types/reaction_count.hpp>

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
