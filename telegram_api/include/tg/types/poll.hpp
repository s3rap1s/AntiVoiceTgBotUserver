#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/message_entity.hpp>
#include <tg/types/poll_option.hpp>

namespace tg {

struct Poll {
    String id;
    String question;
    Optional<Array<MessageEntity>> question_entities;
    Array<PollOption> options;
    Integer total_voter_count;
    Optional<Boolean> is_closed;
    Optional<Boolean> is_anonymous;
    String type;
    Boolean allows_multiple_answers;
    Optional<Integer> corret_option_id;
    Optional<String> explanation;
    Optional<Array<MessageEntity>> explanation_entities;
    Optional<Integer> open_period;
    Optional<Integer> close_date;
};

Poll Parse(const Value& value, To<Poll>);

void Serialize(const Poll& obj, ValueBuilder& builder);

}  // namespace tg
