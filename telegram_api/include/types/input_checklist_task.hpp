#pragma once

#include <types/common.hpp>
#include <types/message_entity.hpp>

namespace tg {

struct InputChecklistTask {
    Integer id;
    String text;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> text_entities;
};

InputChecklistTask Parse(const Value& value, To<InputChecklistTask>);

}  // namespace tg
