#include <tg/types/input_media_photo.hpp>
#include <tg/types/message_entity.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputMediaPhoto Parse(const Value& value, To<InputMediaPhoto>) {
    InputMediaPhoto obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.media = ParseComplex<String>(value["media"]);
    obj.caption = ParseComplex<Optional<String>>(value["caption"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.caption_entities = ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.show_caption_above_media = ParseComplex<Optional<Boolean>>(value["show_caption_above_media"]);
    obj.has_spoiler = ParseComplex<Optional<Boolean>>(value["has_spoiler"]);
    return obj;
}

void Serialize(const InputMediaPhoto& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "media", obj.media);
    internal::Put(builder, "caption", obj.caption);
    internal::Put(builder, "parse_mode", obj.parse_mode);
    internal::Put(builder, "caption_entities", obj.caption_entities);
    internal::Put(builder, "show_caption_above_media", obj.show_caption_above_media);
    internal::Put(builder, "has_spoiler", obj.has_spoiler);
}

}  // namespace tg
