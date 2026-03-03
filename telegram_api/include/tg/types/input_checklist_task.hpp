#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/message_entity.hpp>

namespace tg {

struct InputChecklistTask {
    Integer id;
    String text;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> text_entities;
};

InputChecklistTask Parse(const Value& value, To<InputChecklistTask>);

void Serialize(const InputChecklistTask& obj, ValueBuilder& builder);

}  // namespace tg
