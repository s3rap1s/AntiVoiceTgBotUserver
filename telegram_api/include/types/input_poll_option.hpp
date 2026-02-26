#pragma once

#include "common.hpp"
#include "message_entity.hpp"

namespace tg {

struct InputPollOption {
    String text;
    Optional<String> text_parse_mode;
    Optional<Array<MessageEntity>> text_entities;
};

InputPollOption Parse(const Value& value, To<InputPollOption>);

}  // namespace tg
