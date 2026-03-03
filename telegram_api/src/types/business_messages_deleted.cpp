#include <tg/types/business_messages_deleted.hpp>
#include <tg/types/chat.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BusinessMessagesDeleted Parse(const Value& value, To<BusinessMessagesDeleted>) {
    BusinessMessagesDeleted obj{};
    obj.business_connection_id = ParseComplex<String>(value["business_connection_id"]);
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.message_ids = ParseComplex<Array<Integer>>(value["message_ids"]);
    return obj;
}

void Serialize(const BusinessMessagesDeleted& obj, ValueBuilder& builder) {
    internal::Put(builder, "business_connection_id", obj.business_connection_id);
    internal::Put(builder, "chat", obj.chat);
    internal::Put(builder, "message_ids", obj.message_ids);
}

}  // namespace tg
