#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/chat.hpp>
#include <tg/types/common.hpp>

namespace tg {

struct BusinessMessagesDeleted {
    String business_connection_id;
    Chat chat;
    Array<Integer> message_ids;
};

BusinessMessagesDeleted Parse(const Value& value, To<BusinessMessagesDeleted>);

void Serialize(const BusinessMessagesDeleted& obj, ValueBuilder& builder);

}  // namespace tg
