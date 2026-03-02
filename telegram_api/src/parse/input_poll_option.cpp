#include <tg/types/input_poll_option.hpp>
#include <tg/types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InputPollOption Parse(const Value& value, To<InputPollOption>) {
    InputPollOption obj{};
    obj.text = ParseComplex<String>(value["text"]);
    obj.text_parse_mode =
        ParseComplex<Optional<String>>(value["text_parse_mode"]);
    obj.text_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["text_entities"]);
    return obj;
}

}  // namespace tg
