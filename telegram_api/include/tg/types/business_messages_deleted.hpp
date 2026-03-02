#pragma once

#include <tg/types/common.hpp>
#include <tg/types/chat.hpp>

namespace tg {

struct BusinessMessagesDeleted {
    String business_connection_id;
    Chat chat;
    Array<Integer> message_ids;
};

BusinessMessagesDeleted Parse(const Value& value, To<BusinessMessagesDeleted>);

}  // namespace tg
