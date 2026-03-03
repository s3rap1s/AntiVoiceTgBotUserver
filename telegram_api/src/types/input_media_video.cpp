#include <tg/types/input_media_video.hpp>
#include <tg/types/message_entity.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputMediaVideo Parse(const Value& value, To<InputMediaVideo>) {
    InputMediaVideo obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.media = ParseComplex<String>(value["media"]);
    obj.thumbnail = ParseComplex<Optional<String>>(value["thumbnail"]);
    obj.cover = ParseComplex<Optional<String>>(value["cover"]);
    obj.start_timestamp = ParseComplex<Optional<Integer>>(value["start_timestamp"]);
    obj.caption = ParseComplex<Optional<String>>(value["caption"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.caption_entities = ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.show_caption_above_media = ParseComplex<Optional<Boolean>>(value["show_caption_above_media"]);
    obj.width = ParseComplex<Optional<Boolean>>(value["width"]);
    obj.height = ParseComplex<Optional<Boolean>>(value["height"]);
    obj.duration = ParseComplex<Optional<Boolean>>(value["duration"]);
    obj.supports_streaming = ParseComplex<Optional<Boolean>>(value["supports_streaming"]);
    obj.has_spoiler = ParseComplex<Optional<Boolean>>(value["has_spoiler"]);
    return obj;
}

void Serialize(const InputMediaVideo& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "media", obj.media);
    internal::Put(builder, "thumbnail", obj.thumbnail);
    internal::Put(builder, "cover", obj.cover);
    internal::Put(builder, "start_timestamp", obj.start_timestamp);
    internal::Put(builder, "caption", obj.caption);
    internal::Put(builder, "parse_mode", obj.parse_mode);
    internal::Put(builder, "caption_entities", obj.caption_entities);
    internal::Put(builder, "show_caption_above_media", obj.show_caption_above_media);
    internal::Put(builder, "width", obj.width);
    internal::Put(builder, "height", obj.height);
    internal::Put(builder, "duration", obj.duration);
    internal::Put(builder, "supports_streaming", obj.supports_streaming);
    internal::Put(builder, "has_spoiler", obj.has_spoiler);
}

}  // namespace tg
