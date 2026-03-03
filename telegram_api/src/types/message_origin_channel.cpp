#include <tg/types/chat.hpp>
#include <tg/types/message_origin_channel.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

MessageOriginChannel Parse(const Value& value, To<MessageOriginChannel>) {
    MessageOriginChannel obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.message_id = ParseComplex<Integer>(value["message_id"]);
    obj.author_signature = ParseComplex<Optional<String>>(value["author_signature"]);
    return obj;
}

void Serialize(const MessageOriginChannel& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "date", obj.date);
    internal::Put(builder, "chat", obj.chat);
    internal::Put(builder, "message_id", obj.message_id);
    internal::Put(builder, "author_signature", obj.author_signature);
}

}  // namespace tg
