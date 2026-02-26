#pragma once

#include "chat.hpp"
#include "common.hpp"
#include "reaction_type.hpp"
#include "user.hpp"

namespace tg {

struct MessageReactionUpdated {
    Chat chat;
    Integer message_id;
    Optional<User> user;
    Optional<Chat> actor_chat;
    Integer date;
    Array<ReactionType> old_reactions;
    Array<ReactionType> new_reactions;
};

MessageReactionUpdated Parse(const Value& value, To<MessageReactionUpdated>);

}  // namespace tg
