#include <types/checklist_task.hpp>
#include <types/checklist_tasks_added.hpp>
#include <types/message.hpp>

#include "common.hpp"

namespace tg {

ChecklistTasksAdded Parse(const Value& value, To<ChecklistTasksAdded>) {
    ChecklistTasksAdded obj{};
    obj.checklist_message =
        ParseComplex<MessagePtr>(value["checklist_message"]);
    obj.tasks = ParseComplex<Array<ChecklistTask>>(value["tasks"]);
    return obj;
}

}  // namespace tg
