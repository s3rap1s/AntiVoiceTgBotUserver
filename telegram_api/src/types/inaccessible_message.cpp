#include <tg/types/chat.hpp>
#include <tg/types/inaccessible_message.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InaccessibleMessage Parse(const Value& value, To<InaccessibleMessage>) {
    InaccessibleMessage obj{};
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.message_id = ParseComplex<Integer>(value["message_id"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    return obj;
}

void Serialize(const InaccessibleMessage& obj, ValueBuilder& builder) {
    internal::Put(builder, "chat", obj.chat);
    internal::Put(builder, "message_id", obj.message_id);
    internal::Put(builder, "date", obj.date);
}

}  // namespace tg
