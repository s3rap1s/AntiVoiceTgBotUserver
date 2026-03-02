#include <types/chat.hpp>
#include <types/message_origin_channel.hpp>

#include "common.hpp"

namespace tg {

MessageOriginChannel Parse(const Value& value, To<MessageOriginChannel>) {
    MessageOriginChannel obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.message_id = ParseComplex<Integer>(value["message_id"]);
    obj.author_signature =
        ParseComplex<Optional<String>>(value["author_signature"]);
    return obj;
}

}  // namespace tg
