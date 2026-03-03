#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/checklist_task.hpp>
#include <tg/types/common.hpp>
#include <tg/types/message_ptr.hpp>

namespace tg {

struct ChecklistTasksAdded {
    MessagePtr checklist_message;
    Array<ChecklistTask> tasks;
};

ChecklistTasksAdded Parse(const Value& value, To<ChecklistTasksAdded>);

void Serialize(const ChecklistTasksAdded& obj, ValueBuilder& builder);

}  // namespace tg
