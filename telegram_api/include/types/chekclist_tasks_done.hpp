#pragma once

#include "common.hpp"
#include "message.hpp"

namespace tg {

struct InputChecklist {
    Ptr<Message> checklist_message;
    Optional<Array<Integer>> marked_as_done_task_ids;
    Optional<Array<Integer>> marked_as_not_done_task_ids;
};

InputChecklist Parse(const Value& value, To<InputChecklist>);

}  // namespace tg
