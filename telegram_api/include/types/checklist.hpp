#pragma once

#include <types/checklist_task.hpp>
#include <types/common.hpp>
#include <types/message_entity.hpp>

namespace tg {

struct Checklist {
    String title;
    Optional<Array<MessageEntity>> title_entities;
    Array<ChecklistTask> tasks;
    OptionalTrue others_can_add_tasks;
    OptionalTrue others_can_mark_tasks_as_done;
};

Checklist Parse(const Value& value, To<Checklist>);

}  // namespace tg
