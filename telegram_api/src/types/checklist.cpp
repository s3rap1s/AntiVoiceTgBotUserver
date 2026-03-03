#include <tg/types/checklist.hpp>
#include <tg/types/checklist_task.hpp>
#include <tg/types/message_entity.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

Checklist Parse(const Value& value, To<Checklist>) {
    Checklist obj{};
    obj.title = ParseComplex<String>(value["title"]);
    obj.title_entities = ParseComplex<Optional<Array<MessageEntity>>>(value["title_entities"]);
    obj.tasks = ParseComplex<Array<ChecklistTask>>(value["tasks"]);
    obj.others_can_add_tasks = ParseComplex<OptionalTrue>(value["others_can_add_tasks"]);
    obj.others_can_mark_tasks_as_done = ParseComplex<OptionalTrue>(value["others_can_mark_tasks_as_done"]);
    return obj;
}

void Serialize(const Checklist& obj, ValueBuilder& builder) {
    internal::Put(builder, "title", obj.title);
    internal::Put(builder, "title_entities", obj.title_entities);
    internal::Put(builder, "tasks", obj.tasks);
    internal::Put(builder, "others_can_add_tasks", obj.others_can_add_tasks);
    internal::Put(builder, "others_can_mark_tasks_as_done", obj.others_can_mark_tasks_as_done);
}

}  // namespace tg
