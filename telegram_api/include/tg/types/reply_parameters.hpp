#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/message_entity.hpp>

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

void Serialize(const ReplyParameters& obj, ValueBuilder& builder);

}  // namespace tg
