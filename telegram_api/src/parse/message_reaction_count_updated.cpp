#include <tg/types/chat.hpp>
#include <tg/types/message_reaction_count_updated.hpp>
#include <tg/types/reaction_count.hpp>

#include "common.hpp"

namespace tg {

MessageReactionCountUpdated Parse(const Value& value,
                                  To<MessageReactionCountUpdated>) {
    MessageReactionCountUpdated obj{};
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.message_id = ParseComplex<Integer>(value["message_id"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.reactions = ParseComplex<Array<ReactionCount>>(value["reactions"]);
    return obj;
}

}  // namespace tg
