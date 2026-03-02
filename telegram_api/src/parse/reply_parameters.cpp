#include <tg/types/message_entity.hpp>
#include <tg/types/reply_parameters.hpp>

#include "common.hpp"

namespace tg {

ReplyParameters Parse(const Value& value, To<ReplyParameters>) {
    ReplyParameters obj{};
    obj.message_id = ParseComplex<Integer>(value["message_id"]);
    obj.chat_id =
        ParseComplex<Optional<OneOf<Integer, String>>>(value["chat_id"]);
    obj.allow_sending_without_reply =
        ParseComplex<Optional<Boolean>>(value["allow_sending_without_reply"]);
    obj.quote = ParseComplex<Optional<String>>(value["quote"]);
    obj.quote_parse_mode =
        ParseComplex<Optional<String>>(value["quote_parse_mode"]);
    obj.quote_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["quote_entities"]);
    obj.quote_position =
        ParseComplex<Optional<Integer>>(value["quote_position"]);
    obj.checklist_task_id =
        ParseComplex<Optional<Integer>>(value["checklist_task_id"]);
    return obj;
}

}  // namespace tg
