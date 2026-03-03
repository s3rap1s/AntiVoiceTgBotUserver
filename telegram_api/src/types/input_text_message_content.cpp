#include <tg/types/input_text_message_content.hpp>
#include <tg/types/link_preview_options.hpp>
#include <tg/types/message_entity.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputTextMessageContent Parse(const Value& value, To<InputTextMessageContent>) {
    InputTextMessageContent obj{};
    obj.message_text = ParseComplex<String>(value["message_text"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.entities = ParseComplex<Optional<Array<MessageEntity>>>(value["entities"]);
    obj.link_preview_options = ParseComplex<Optional<LinkPreviewOptions>>(value["link_preview_options"]);
    return obj;
}

void Serialize(const InputTextMessageContent& obj, ValueBuilder& builder) {
    internal::Put(builder, "message_text", obj.message_text);
    internal::Put(builder, "parse_mode", obj.parse_mode);
    internal::Put(builder, "entities", obj.entities);
    internal::Put(builder, "link_preview_options", obj.link_preview_options);
}

}  // namespace tg
