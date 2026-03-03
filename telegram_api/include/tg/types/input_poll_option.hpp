#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/message_entity.hpp>

namespace tg {

struct InputPollOption {
    String text;
    Optional<String> text_parse_mode;
    Optional<Array<MessageEntity>> text_entities;
};

InputPollOption Parse(const Value& value, To<InputPollOption>);

void Serialize(const InputPollOption& obj, ValueBuilder& builder);

}  // namespace tg
