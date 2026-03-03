#include <tg/types/chat.hpp>
#include <tg/types/checklist_task.hpp>
#include <tg/types/message_entity.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChecklistTask Parse(const Value& value, To<ChecklistTask>) {
    ChecklistTask obj{};
    obj.id = ParseComplex<Integer>(value["id"]);
    obj.text = ParseComplex<String>(value["text"]);
    obj.text_entities = ParseComplex<Optional<Array<MessageEntity>>>(value["text_entities"]);
    obj.completed_by_user = ParseComplex<Optional<User>>(value["completed_by_user"]);
    obj.completed_by_chat = ParseComplex<Optional<Chat>>(value["completed_by_chat"]);
    obj.completion_date = ParseComplex<Optional<Integer>>(value["completion_date"]);
    return obj;
}

void Serialize(const ChecklistTask& obj, ValueBuilder& builder) {
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "text", obj.text);
    internal::Put(builder, "text_entities", obj.text_entities);
    internal::Put(builder, "completed_by_user", obj.completed_by_user);
    internal::Put(builder, "completed_by_chat", obj.completed_by_chat);
    internal::Put(builder, "completion_date", obj.completion_date);
}

}  // namespace tg
