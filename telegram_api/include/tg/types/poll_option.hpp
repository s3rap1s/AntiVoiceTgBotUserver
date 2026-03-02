#pragma once

#include <tg/types/common.hpp>
#include <tg/types/message_entity.hpp>

namespace tg {

struct PollOption {
    String text;
    Optional<Array<MessageEntity>> text_entities;
    Integer voter_count;
};

PollOption Parse(const Value& value, To<PollOption>);

}  // namespace tg
