#include <tg/types/file.hpp>
#include <tg/types/mask_position.hpp>
#include <tg/types/photo_size.hpp>
#include <tg/types/sticker.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

Sticker Parse(const Value& value, To<Sticker>) {
    Sticker obj{};
    obj.file_id = ParseComplex<String>(value["file_id"]);
    obj.file_unique_id = ParseComplex<String>(value["file_unique_id"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.width = ParseComplex<Integer>(value["width"]);
    obj.height = ParseComplex<Integer>(value["height"]);
    obj.is_animated = ParseComplex<Boolean>(value["is_animated"]);
    obj.is_video = ParseComplex<Boolean>(value["is_video"]);
    obj.thumbnail = ParseComplex<Optional<PhotoSize>>(value["thumbnail"]);
    obj.emoji = ParseComplex<Optional<String>>(value["emoji"]);
    obj.set_name = ParseComplex<Optional<String>>(value["set_name"]);
    obj.premium_animation = ParseComplex<Optional<File>>(value["premium_animation"]);
    obj.mask_position = ParseComplex<Optional<MaskPosition>>(value["mask_position"]);
    obj.custom_emoji_id = ParseComplex<Optional<String>>(value["custom_emoji_id"]);
    obj.needs_repainting = ParseComplex<OptionalTrue>(value["needs_repainting"]);
    obj.file_size = ParseComplex<Optional<Integer>>(value["file_size"]);
    return obj;
}

void Serialize(const Sticker& obj, ValueBuilder& builder) {
    internal::Put(builder, "file_id", obj.file_id);
    internal::Put(builder, "file_unique_id", obj.file_unique_id);
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "width", obj.width);
    internal::Put(builder, "height", obj.height);
    internal::Put(builder, "is_animated", obj.is_animated);
    internal::Put(builder, "is_video", obj.is_video);
    internal::Put(builder, "thumbnail", obj.thumbnail);
    internal::Put(builder, "emoji", obj.emoji);
    internal::Put(builder, "set_name", obj.set_name);
    internal::Put(builder, "premium_animation", obj.premium_animation);
    internal::Put(builder, "mask_position", obj.mask_position);
    internal::Put(builder, "custom_emoji_id", obj.custom_emoji_id);
    internal::Put(builder, "needs_repainting", obj.needs_repainting);
    internal::Put(builder, "file_size", obj.file_size);
}

}  // namespace tg
