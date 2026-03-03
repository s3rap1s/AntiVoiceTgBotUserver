#include <tg/types/message_origin_user.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

MessageOriginUser Parse(const Value& value, To<MessageOriginUser>) {
    MessageOriginUser obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.sender_user = ParseComplex<User>(value["sender_user"]);
    return obj;
}

void Serialize(const MessageOriginUser& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "date", obj.date);
    internal::Put(builder, "sender_user", obj.sender_user);
}

}  // namespace tg
