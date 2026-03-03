#include <tg/types/input_poll_option.hpp>
#include <tg/types/message_entity.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputPollOption Parse(const Value& value, To<InputPollOption>) {
    InputPollOption obj{};
    obj.text = ParseComplex<String>(value["text"]);
    obj.text_parse_mode = ParseComplex<Optional<String>>(value["text_parse_mode"]);
    obj.text_entities = ParseComplex<Optional<Array<MessageEntity>>>(value["text_entities"]);
    return obj;
}

void Serialize(const InputPollOption& obj, ValueBuilder& builder) {
    internal::Put(builder, "text", obj.text);
    internal::Put(builder, "text_parse_mode", obj.text_parse_mode);
    internal::Put(builder, "text_entities", obj.text_entities);
}

}  // namespace tg
