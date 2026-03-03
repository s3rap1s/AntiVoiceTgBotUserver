#include <tg/types/message_entity.hpp>
#include <tg/types/poll.hpp>
#include <tg/types/poll_option.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

Poll Parse(const Value& value, To<Poll>) {
    Poll obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.question = ParseComplex<String>(value["question"]);
    obj.question_entities = ParseComplex<Optional<Array<MessageEntity>>>(value["question_entities"]);
    obj.options = ParseComplex<Array<PollOption>>(value["options"]);
    obj.total_voter_count = ParseComplex<Integer>(value["total_voter_count"]);
    obj.is_closed = ParseComplex<Optional<Boolean>>(value["is_closed"]);
    obj.is_anonymous = ParseComplex<Optional<Boolean>>(value["is_anonymous"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.allows_multiple_answers = ParseComplex<Boolean>(value["allows_multiple_answers"]);
    obj.corret_option_id = ParseComplex<Optional<Integer>>(value["corret_option_id"]);
    obj.explanation = ParseComplex<Optional<String>>(value["explanation"]);
    obj.explanation_entities = ParseComplex<Optional<Array<MessageEntity>>>(value["explanation_entities"]);
    obj.open_period = ParseComplex<Optional<Integer>>(value["open_period"]);
    obj.close_date = ParseComplex<Optional<Integer>>(value["close_date"]);
    return obj;
}

void Serialize(const Poll& obj, ValueBuilder& builder) {
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "question", obj.question);
    internal::Put(builder, "question_entities", obj.question_entities);
    internal::Put(builder, "options", obj.options);
    internal::Put(builder, "total_voter_count", obj.total_voter_count);
    internal::Put(builder, "is_closed", obj.is_closed);
    internal::Put(builder, "is_anonymous", obj.is_anonymous);
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "allows_multiple_answers", obj.allows_multiple_answers);
    internal::Put(builder, "corret_option_id", obj.corret_option_id);
    internal::Put(builder, "explanation", obj.explanation);
    internal::Put(builder, "explanation_entities", obj.explanation_entities);
    internal::Put(builder, "open_period", obj.open_period);
    internal::Put(builder, "close_date", obj.close_date);
}

}  // namespace tg
