#include <types/chat.hpp>
#include <types/message_origin_chat.hpp>

#include "common.hpp"

namespace tg {

MessageOriginChat Parse(const Value& value, To<MessageOriginChat>) {
    MessageOriginChat obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.sender_chat = ParseComplex<Chat>(value["sender_chat"]);
    obj.author_signature =
        ParseComplex<Optional<String>>(value["author_signature"]);
    return obj;
}

}  // namespace tg
