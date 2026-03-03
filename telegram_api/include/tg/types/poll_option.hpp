#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/message_entity.hpp>

namespace tg {

struct PollOption {
    String text;
    Optional<Array<MessageEntity>> text_entities;
    Integer voter_count;
};

PollOption Parse(const Value& value, To<PollOption>);

void Serialize(const PollOption& obj, ValueBuilder& builder);

}  // namespace tg
