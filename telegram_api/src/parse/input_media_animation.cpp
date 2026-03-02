#include <types/input_media_animation.hpp>
#include <types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InputMediaAnimation Parse(const Value& value, To<InputMediaAnimation>) {
    InputMediaAnimation obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.media = ParseComplex<String>(value["media"]);
    obj.thumbnail = ParseComplex<Optional<String>>(value["thumbnail"]);
    obj.caption = ParseComplex<Optional<String>>(value["caption"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.caption_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.show_caption_above_media =
        ParseComplex<Optional<Boolean>>(value["show_caption_above_media"]);
    obj.width = ParseComplex<Optional<Boolean>>(value["width"]);
    obj.height = ParseComplex<Optional<Boolean>>(value["height"]);
    obj.duration = ParseComplex<Optional<Boolean>>(value["duration"]);
    obj.has_spoiler = ParseComplex<Optional<Boolean>>(value["has_spoiler"]);
    return obj;
}

}  // namespace tg
