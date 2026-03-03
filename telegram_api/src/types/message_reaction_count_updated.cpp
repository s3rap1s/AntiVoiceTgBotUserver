#include <tg/types/chat.hpp>
#include <tg/types/message_reaction_count_updated.hpp>
#include <tg/types/reaction_count.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

MessageReactionCountUpdated Parse(const Value& value, To<MessageReactionCountUpdated>) {
    MessageReactionCountUpdated obj{};
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.message_id = ParseComplex<Integer>(value["message_id"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.reactions = ParseComplex<Array<ReactionCount>>(value["reactions"]);
    return obj;
}

void Serialize(const MessageReactionCountUpdated& obj, ValueBuilder& builder) {
    internal::Put(builder, "chat", obj.chat);
    internal::Put(builder, "message_id", obj.message_id);
    internal::Put(builder, "date", obj.date);
    internal::Put(builder, "reactions", obj.reactions);
}

}  // namespace tg
