#include <tg/types/checklist_task.hpp>
#include <tg/types/checklist_tasks_added.hpp>
#include <tg/types/message.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChecklistTasksAdded Parse(const Value& value, To<ChecklistTasksAdded>) {
    ChecklistTasksAdded obj{};
    obj.checklist_message = ParseComplex<MessagePtr>(value["checklist_message"]);
    obj.tasks = ParseComplex<Array<ChecklistTask>>(value["tasks"]);
    return obj;
}

void Serialize(const ChecklistTasksAdded& obj, ValueBuilder& builder) {
    internal::Put(builder, "checklist_message", obj.checklist_message);
    internal::Put(builder, "tasks", obj.tasks);
}

}  // namespace tg
