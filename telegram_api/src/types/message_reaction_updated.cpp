#include <tg/types/chat.hpp>
#include <tg/types/message_reaction_updated.hpp>
#include <tg/types/reaction_type.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

MessageReactionUpdated Parse(const Value& value, To<MessageReactionUpdated>) {
    MessageReactionUpdated obj{};
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.message_id = ParseComplex<Integer>(value["message_id"]);
    obj.user = ParseComplex<Optional<User>>(value["user"]);
    obj.actor_chat = ParseComplex<Optional<Chat>>(value["actor_chat"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.old_reactions = ParseComplex<Array<ReactionType>>(value["old_reactions"]);
    obj.new_reactions = ParseComplex<Array<ReactionType>>(value["new_reactions"]);
    return obj;
}

void Serialize(const MessageReactionUpdated& obj, ValueBuilder& builder) {
    internal::Put(builder, "chat", obj.chat);
    internal::Put(builder, "message_id", obj.message_id);
    internal::Put(builder, "user", obj.user);
    internal::Put(builder, "actor_chat", obj.actor_chat);
    internal::Put(builder, "date", obj.date);
    internal::Put(builder, "old_reactions", obj.old_reactions);
    internal::Put(builder, "new_reactions", obj.new_reactions);
}

}  // namespace tg
