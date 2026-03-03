#include <tg/types/input_media_audio.hpp>
#include <tg/types/message_entity.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputMediaAudio Parse(const Value& value, To<InputMediaAudio>) {
    InputMediaAudio obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.media = ParseComplex<String>(value["media"]);
    obj.thumbnail = ParseComplex<Optional<String>>(value["thumbnail"]);
    obj.caption = ParseComplex<Optional<String>>(value["caption"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.caption_entities = ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.duration = ParseComplex<Optional<Boolean>>(value["duration"]);
    obj.performer = ParseComplex<Optional<String>>(value["performer"]);
    obj.title = ParseComplex<Optional<String>>(value["title"]);
    return obj;
}

void Serialize(const InputMediaAudio& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "media", obj.media);
    internal::Put(builder, "thumbnail", obj.thumbnail);
    internal::Put(builder, "caption", obj.caption);
    internal::Put(builder, "parse_mode", obj.parse_mode);
    internal::Put(builder, "caption_entities", obj.caption_entities);
    internal::Put(builder, "duration", obj.duration);
    internal::Put(builder, "performer", obj.performer);
    internal::Put(builder, "title", obj.title);
}

}  // namespace tg
