#pragma once

#include <types/chat.hpp>
#include <types/common.hpp>

namespace tg {

struct InaccessibleMessage {
    Chat chat;
    Integer message_id;
    Integer date;
};

InaccessibleMessage Parse(const Value& value, To<InaccessibleMessage>);

}  // namespace tg
