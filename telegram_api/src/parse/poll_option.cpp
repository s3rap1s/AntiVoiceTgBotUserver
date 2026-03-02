#include <tg/types/message_entity.hpp>
#include <tg/types/poll_option.hpp>

#include "common.hpp"

namespace tg {

PollOption Parse(const Value& value, To<PollOption>) {
    PollOption obj{};
    obj.text = ParseComplex<String>(value["text"]);
    obj.text_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["text_entities"]);
    obj.voter_count = ParseComplex<Integer>(value["voter_count"]);
    return obj;
}

}  // namespace tg
