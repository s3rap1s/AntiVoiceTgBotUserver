#include <tg/types/message_id.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

MessageId Parse(const Value& value, To<MessageId>) {
    MessageId obj{};
    obj.message_id = ParseComplex<Integer>(value["message_id"]);
    return obj;
}

void Serialize(const MessageId& obj, ValueBuilder& builder) { internal::Put(builder, "message_id", obj.message_id); }

}  // namespace tg
