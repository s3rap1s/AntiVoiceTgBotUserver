#pragma once

#include "checklist_task.hpp"
#include "common.hpp"

namespace tg {

struct Message;

struct ChecklistTasksAdded {
    Ptr<Message> checklist_message;
    Array<ChecklistTask> tasks;
};

ChecklistTasksAdded Parse(const Value& value, To<ChecklistTasksAdded>);

}  // namespace tg
