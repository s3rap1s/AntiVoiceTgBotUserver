#include <tg/types/input_media_document.hpp>
#include <tg/types/message_entity.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputMediaDocument Parse(const Value& value, To<InputMediaDocument>) {
    InputMediaDocument obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.media = ParseComplex<String>(value["media"]);
    obj.thumbnail = ParseComplex<Optional<String>>(value["thumbnail"]);
    obj.caption = ParseComplex<Optional<String>>(value["caption"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.caption_entities = ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.disable_content_type_detection = ParseComplex<Optional<Boolean>>(value["disable_content_type_detection"]);
    return obj;
}

void Serialize(const InputMediaDocument& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "media", obj.media);
    internal::Put(builder, "thumbnail", obj.thumbnail);
    internal::Put(builder, "caption", obj.caption);
    internal::Put(builder, "parse_mode", obj.parse_mode);
    internal::Put(builder, "caption_entities", obj.caption_entities);
    internal::Put(builder, "disable_content_type_detection", obj.disable_content_type_detection);
}

}  // namespace tg
