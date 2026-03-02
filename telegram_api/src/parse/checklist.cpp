#include <types/checklist.hpp>
#include <types/checklist_task.hpp>
#include <types/message_entity.hpp>

#include "common.hpp"

namespace tg {

Checklist Parse(const Value& value, To<Checklist>) {
    Checklist obj{};
    obj.title = ParseComplex<String>(value["title"]);
    obj.title_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["title_entities"]);
    obj.tasks = ParseComplex<Array<ChecklistTask>>(value["tasks"]);
    obj.others_can_add_tasks =
        ParseComplex<OptionalTrue>(value["others_can_add_tasks"]);
    obj.others_can_mark_tasks_as_done =
        ParseComplex<OptionalTrue>(value["others_can_mark_tasks_as_done"]);
    return obj;
}

}  // namespace tg
