#pragma once

#include <types/chat.hpp>
#include <types/common.hpp>
#include <types/reaction_type.hpp>
#include <types/user.hpp>

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
