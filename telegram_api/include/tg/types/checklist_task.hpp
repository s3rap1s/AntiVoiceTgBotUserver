#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/chat.hpp>
#include <tg/types/common.hpp>
#include <tg/types/message_entity.hpp>
#include <tg/types/user.hpp>

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

void Serialize(const ChecklistTask& obj, ValueBuilder& builder);

}  // namespace tg
