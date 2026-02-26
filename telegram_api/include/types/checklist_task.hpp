#pragma once

#include "chat.hpp"
#include "common.hpp"
#include "message_entity.hpp"
#include "user.hpp"

namespace tg {

struct ChecklistTask {
    Integer id;
    String text;
    Optional<Array<MessageEntity>> text_entities;
    Optional<User> completed_by_user;
    Optional<Chat> completed_by_chat;
    Optional<Integer> completion_date;
};

ChecklistTask Parse(const Value& value, To<ChecklistTask>);

}  // namespace tg
