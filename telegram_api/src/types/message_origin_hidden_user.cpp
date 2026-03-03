#include <tg/types/message_origin_hidden_user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

MessageOriginHiddenUser Parse(const Value& value, To<MessageOriginHiddenUser>) {
    MessageOriginHiddenUser obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.sender_user_name = ParseComplex<String>(value["sender_user_name"]);
    return obj;
}

void Serialize(const MessageOriginHiddenUser& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "date", obj.date);
    internal::Put(builder, "sender_user_name", obj.sender_user_name);
}

}  // namespace tg
