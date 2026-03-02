#pragma once

#include <tg/types/common.hpp>
#include <tg/types/input_checklist_task.hpp>
#include <tg/types/message_entity.hpp>

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
