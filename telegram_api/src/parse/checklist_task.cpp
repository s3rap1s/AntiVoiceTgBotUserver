#include <tg/types/chat.hpp>
#include <tg/types/checklist_task.hpp>
#include <tg/types/message_entity.hpp>
#include <tg/types/user.hpp>

#include "common.hpp"

namespace tg {

ChecklistTask Parse(const Value& value, To<ChecklistTask>) {
    ChecklistTask obj{};
    obj.id = ParseComplex<Integer>(value["id"]);
    obj.text = ParseComplex<String>(value["text"]);
    obj.text_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["text_entities"]);
    obj.completed_by_user =
        ParseComplex<Optional<User>>(value["completed_by_user"]);
    obj.completed_by_chat =
        ParseComplex<Optional<Chat>>(value["completed_by_chat"]);
    obj.completion_date =
        ParseComplex<Optional<Integer>>(value["completion_date"]);
    return obj;
}

}  // namespace tg
