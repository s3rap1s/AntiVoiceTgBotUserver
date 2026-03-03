#include <tg/types/message_entity.hpp>
#include <tg/types/reply_parameters.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ReplyParameters Parse(const Value& value, To<ReplyParameters>) {
    ReplyParameters obj{};
    obj.message_id = ParseComplex<Integer>(value["message_id"]);
    obj.chat_id = ParseComplex<Optional<OneOf<Integer, String>>>(value["chat_id"]);
    obj.allow_sending_without_reply = ParseComplex<Optional<Boolean>>(value["allow_sending_without_reply"]);
    obj.quote = ParseComplex<Optional<String>>(value["quote"]);
    obj.quote_parse_mode = ParseComplex<Optional<String>>(value["quote_parse_mode"]);
    obj.quote_entities = ParseComplex<Optional<Array<MessageEntity>>>(value["quote_entities"]);
    obj.quote_position = ParseComplex<Optional<Integer>>(value["quote_position"]);
    obj.checklist_task_id = ParseComplex<Optional<Integer>>(value["checklist_task_id"]);
    return obj;
}

void Serialize(const ReplyParameters& obj, ValueBuilder& builder) {
    internal::Put(builder, "message_id", obj.message_id);
    internal::Put(builder, "chat_id", obj.chat_id);
    internal::Put(builder, "allow_sending_without_reply", obj.allow_sending_without_reply);
    internal::Put(builder, "quote", obj.quote);
    internal::Put(builder, "quote_parse_mode", obj.quote_parse_mode);
    internal::Put(builder, "quote_entities", obj.quote_entities);
    internal::Put(builder, "quote_position", obj.quote_position);
    internal::Put(builder, "checklist_task_id", obj.checklist_task_id);
}

}  // namespace tg
