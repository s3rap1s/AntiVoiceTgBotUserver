#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/chat.hpp>
#include <tg/types/common.hpp>
#include <tg/types/reaction_type.hpp>
#include <tg/types/user.hpp>

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

void Serialize(const MessageReactionUpdated& obj, ValueBuilder& builder);

}  // namespace tg
