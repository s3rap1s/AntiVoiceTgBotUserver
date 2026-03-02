#pragma once

#include <tg/types/common.hpp>
#include <tg/types/message_ptr.hpp>

namespace tg {

struct ChecklistTasksDone {
    MessagePtr checklist_message;
    Optional<Array<Integer>> marked_as_done_task_ids;
    Optional<Array<Integer>> marked_as_not_done_task_ids;
};

ChecklistTasksDone Parse(const Value& value, To<ChecklistTasksDone>);

}  // namespace tg
