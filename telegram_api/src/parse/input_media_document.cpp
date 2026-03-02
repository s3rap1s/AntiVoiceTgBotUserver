#include <types/input_media_document.hpp>
#include <types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InputMediaDocument Parse(const Value& value, To<InputMediaDocument>) {
    InputMediaDocument obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.media = ParseComplex<String>(value["media"]);
    obj.thumbnail = ParseComplex<Optional<String>>(value["thumbnail"]);
    obj.caption = ParseComplex<Optional<String>>(value["caption"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.caption_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.disable_content_type_detection = ParseComplex<Optional<Boolean>>(
        value["disable_content_type_detection"]);
    return obj;
}

}  // namespace tg
