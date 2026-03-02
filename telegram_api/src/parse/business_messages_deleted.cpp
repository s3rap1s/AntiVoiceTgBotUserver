#include <types/business_messages_deleted.hpp>
#include <types/chat.hpp>

#include "common.hpp"

namespace tg {

BusinessMessagesDeleted Parse(const Value& value, To<BusinessMessagesDeleted>) {
    BusinessMessagesDeleted obj{};
    obj.business_connection_id =
        ParseComplex<String>(value["business_connection_id"]);
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.message_ids = ParseComplex<Array<Integer>>(value["message_ids"]);
    return obj;
}

}  // namespace tg
