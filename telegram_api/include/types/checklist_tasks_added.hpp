#pragma once

#include <types/checklist_task.hpp>
#include <types/common.hpp>
#include <types/message_ptr.hpp>

namespace tg {

struct ChecklistTasksAdded {
    MessagePtr checklist_message;
    Array<ChecklistTask> tasks;
};

ChecklistTasksAdded Parse(const Value& value, To<ChecklistTasksAdded>);

}  // namespace tg
