#include <tg/types/checklist_tasks_done.hpp>
#include <tg/types/message.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChecklistTasksDone Parse(const Value& value, To<ChecklistTasksDone>) {
    ChecklistTasksDone obj{};
    obj.checklist_message = ParseComplex<MessagePtr>(value["checklist_message"]);
    obj.marked_as_done_task_ids = ParseComplex<Optional<Array<Integer>>>(value["marked_as_done_task_ids"]);
    obj.marked_as_not_done_task_ids = ParseComplex<Optional<Array<Integer>>>(value["marked_as_not_done_task_ids"]);
    return obj;
}

void Serialize(const ChecklistTasksDone& obj, ValueBuilder& builder) {
    internal::Put(builder, "checklist_message", obj.checklist_message);
    internal::Put(builder, "marked_as_done_task_ids", obj.marked_as_done_task_ids);
    internal::Put(builder, "marked_as_not_done_task_ids", obj.marked_as_not_done_task_ids);
}

}  // namespace tg
