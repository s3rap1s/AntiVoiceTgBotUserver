#include <tg/types/message_entity.hpp>
#include <tg/types/poll.hpp>
#include <tg/types/poll_option.hpp>

#include "common.hpp"

namespace tg {

Poll Parse(const Value& value, To<Poll>) {
    Poll obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.question = ParseComplex<String>(value["question"]);
    obj.question_entities = ParseComplex<Optional<Array<MessageEntity>>>(
        value["question_entities"]);
    obj.options = ParseComplex<Array<PollOption>>(value["options"]);
    obj.total_voter_count = ParseComplex<Integer>(value["total_voter_count"]);
    obj.is_closed = ParseComplex<Optional<Boolean>>(value["is_closed"]);
    obj.is_anonymous = ParseComplex<Optional<Boolean>>(value["is_anonymous"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.allows_multiple_answers =
        ParseComplex<Boolean>(value["allows_multiple_answers"]);
    obj.corret_option_id =
        ParseComplex<Optional<Integer>>(value["corret_option_id"]);
    obj.explanation = ParseComplex<Optional<String>>(value["explanation"]);
    obj.explanation_entities = ParseComplex<Optional<Array<MessageEntity>>>(
        value["explanation_entities"]);
    obj.open_period = ParseComplex<Optional<Integer>>(value["open_period"]);
    obj.close_date = ParseComplex<Optional<Integer>>(value["close_date"]);
    return obj;
}

}  // namespace tg
