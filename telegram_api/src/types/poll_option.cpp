#include <tg/types/message_entity.hpp>
#include <tg/types/poll_option.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

PollOption Parse(const Value& value, To<PollOption>) {
    PollOption obj{};
    obj.text = ParseComplex<String>(value["text"]);
    obj.text_entities = ParseComplex<Optional<Array<MessageEntity>>>(value["text_entities"]);
    obj.voter_count = ParseComplex<Integer>(value["voter_count"]);
    return obj;
}

void Serialize(const PollOption& obj, ValueBuilder& builder) {
    internal::Put(builder, "text", obj.text);
    internal::Put(builder, "text_entities", obj.text_entities);
    internal::Put(builder, "voter_count", obj.voter_count);
}

}  // namespace tg
