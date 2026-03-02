#pragma once

#include <types/common.hpp>
#include <types/message_entity.hpp>

namespace tg {

struct ReplyParameters {
    Integer message_id;
    Optional<OneOf<Integer, String>> chat_id;
    Optional<Boolean> allow_sending_without_reply;
    Optional<String> quote;
    Optional<String> quote_parse_mode;
    Optional<Array<MessageEntity>> quote_entities;
    Optional<Integer> quote_position;
    Optional<Integer> checklist_task_id;
};

ReplyParameters Parse(const Value& value, To<ReplyParameters>);

}  // namespace tg
