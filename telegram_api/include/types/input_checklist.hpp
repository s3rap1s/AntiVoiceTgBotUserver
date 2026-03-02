#pragma once

#include <types/common.hpp>
#include <types/input_checklist_task.hpp>
#include <types/message_entity.hpp>

namespace tg {

struct InputChecklist {
    String title;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> title_entities;
    Array<InputChecklistTask> tasks;
    Optional<Boolean> others_can_add_tasks;
    Optional<Boolean> others_can_mark_tasks_as_done;
};

InputChecklist Parse(const Value& value, To<InputChecklist>);

}  // namespace tg
