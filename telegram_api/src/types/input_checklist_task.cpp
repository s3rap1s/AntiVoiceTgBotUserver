#include <tg/types/input_checklist_task.hpp>
#include <tg/types/message_entity.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputChecklistTask Parse(const Value& value, To<InputChecklistTask>) {
    InputChecklistTask obj{};
    obj.id = ParseComplex<Integer>(value["id"]);
    obj.text = ParseComplex<String>(value["text"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.text_entities = ParseComplex<Optional<Array<MessageEntity>>>(value["text_entities"]);
    return obj;
}

void Serialize(const InputChecklistTask& obj, ValueBuilder& builder) {
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "text", obj.text);
    internal::Put(builder, "parse_mode", obj.parse_mode);
    internal::Put(builder, "text_entities", obj.text_entities);
}

}  // namespace tg
