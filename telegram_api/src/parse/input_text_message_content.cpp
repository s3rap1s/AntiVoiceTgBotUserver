#include <types/input_text_message_content.hpp>
#include <types/link_preview_options.hpp>
#include <types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InputTextMessageContent Parse(const Value& value, To<InputTextMessageContent>) {
    InputTextMessageContent obj{};
    obj.message_text = ParseComplex<String>(value["message_text"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["entities"]);
    obj.link_preview_options = ParseComplex<Optional<LinkPreviewOptions>>(
        value["link_preview_options"]);
    return obj;
}

}  // namespace tg
