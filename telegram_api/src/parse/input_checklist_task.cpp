#include <tg/types/input_checklist_task.hpp>
#include <tg/types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InputChecklistTask Parse(const Value& value, To<InputChecklistTask>) {
    InputChecklistTask obj{};
    obj.id = ParseComplex<Integer>(value["id"]);
    obj.text = ParseComplex<String>(value["text"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.text_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["text_entities"]);
    return obj;
}

}  // namespace tg
