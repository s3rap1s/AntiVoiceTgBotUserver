#include <types/input_media_photo.hpp>
#include <types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InputMediaPhoto Parse(const Value& value, To<InputMediaPhoto>) {
    InputMediaPhoto obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.media = ParseComplex<String>(value["media"]);
    obj.caption = ParseComplex<Optional<String>>(value["caption"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.caption_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.show_caption_above_media =
        ParseComplex<Optional<Boolean>>(value["show_caption_above_media"]);
    obj.has_spoiler = ParseComplex<Optional<Boolean>>(value["has_spoiler"]);
    return obj;
}

}  // namespace tg
