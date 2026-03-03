#include <tg/types/chat.hpp>
#include <tg/types/message_origin_chat.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

MessageOriginChat Parse(const Value& value, To<MessageOriginChat>) {
    MessageOriginChat obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.sender_chat = ParseComplex<Chat>(value["sender_chat"]);
    obj.author_signature = ParseComplex<Optional<String>>(value["author_signature"]);
    return obj;
}

void Serialize(const MessageOriginChat& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "date", obj.date);
    internal::Put(builder, "sender_chat", obj.sender_chat);
    internal::Put(builder, "author_signature", obj.author_signature);
}

}  // namespace tg
