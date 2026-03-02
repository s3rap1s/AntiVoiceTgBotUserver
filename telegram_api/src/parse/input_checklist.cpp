#include <types/input_checklist.hpp>
#include <types/input_checklist_task.hpp>
#include <types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InputChecklist Parse(const Value& value, To<InputChecklist>) {
    InputChecklist obj{};
    obj.title = ParseComplex<String>(value["title"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.title_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["title_entities"]);
    obj.tasks = ParseComplex<Array<InputChecklistTask>>(value["tasks"]);
    obj.others_can_add_tasks =
        ParseComplex<Optional<Boolean>>(value["others_can_add_tasks"]);
    obj.others_can_mark_tasks_as_done =
        ParseComplex<Optional<Boolean>>(value["others_can_mark_tasks_as_done"]);
    return obj;
}

}  // namespace tg
